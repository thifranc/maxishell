/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 11:21:05 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/07 13:25:32 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	error(char *cmd, int flag)
{
	if (!cmd)
		ft_putstr("usage : command without arguments\n");
	else
	{
		if (flag == 1)
			ft_putstr(ft_ptrf("%s : command not found\n", cmd));
		if (flag == 2)
			ft_putstr(ft_ptrf("usage : setenv [name] [value] [crash]"
						"\nThere is no enough args\n"));
		if (flag == 3)
			ft_putstr(ft_ptrf("Too many args : %s\n", cmd));
		if (flag == 4)
			ft_putstr(ft_ptrf("Var %s don't exist. We can't erase it\n", cmd));
		if (flag == 5)
			ft_putstr(ft_ptrf("Execve of %s failed : don't exist\n", cmd));
		if (flag == 6)
			ft_putstr(ft_ptrf("Execve of %s failed : no exec rights\n", cmd));
		if (flag == 7)
			ft_putstr(ft_ptrf("usage: unsetenv [var_name]\nVar=%s\n", cmd));
	}
}

void	inception(char **args, t_list *env)
{
	pid_t	father;

	if (args[0] || !env)
		return (error(NULL, 0));
	else
	{
		father = fork();
		if (father)
			wait(&father);
		else
			g_cmd_list->next = NULL;
	}
}

int		fork_me(char *path, char **args, t_list *aim)
{
	pid_t	father;
	char	**env;

	if (access(path, F_OK) == -1 || access(path, X_OK) == -1)
	{
		if (access(path, F_OK) == -1)
			error(path, 5);
		else if (access(path, X_OK) == -1)
			error(path, 6);
		return (0);
	}
	father = fork();
	if (father)
		wait(&father);
	else
	{
		env = make_tab(aim);
		execve(path, args, env);
		ft_deltab((void**)env);
	}
	return (1);
}

void	exec_binary(char **args, t_list *aim)
{
	t_list	*tmp;

	tmp = g_bin;
	if (args[0][0] == '/' && fork_me(args[0], args, aim))
		return ;
	while (tmp)
	{
		if (!ft_strcmp(args[0], (char*)tmp->name) &&
				fork_me(tmp->value, args, aim))
			return ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (error(args[0], 1));
}

void	route_me(char **args, t_list *aim)
{
	int			i;
	static char	*builtin[] =
	{"cd", "env", "setenv", "unsetenv", "exit", "minishell",
		"clear"};
	static void	(*f[8])(char **args, t_list *aim) =
	{ft_cd, ft_env, ft_setenv, ft_unsetenv, ft_exit, inception,
		ft_clear};

	i = 0;
	if (!args[0])
	{
		ft_putstr("no command entered\n");
		return ;
	}
	while (builtin[i] && ft_strcmp(builtin[i], args[0]))
		i++;
	if (builtin[i])
		f[i](args + 1, aim);
	else
	{
		if (!ft_strncmp("./", args[0], 2) && !fork_me(args[0], args, aim))
			return ;
		else if (ft_strncmp("./", args[0], 2))
			exec_binary(args, aim);
	}
}
