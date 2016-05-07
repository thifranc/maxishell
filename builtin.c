/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 14:15:20 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/07 14:39:27 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	ft_unset(char *env, t_list *aim)
{
	t_list	*node;
	t_list	*tmp;
	int		ct;

	node = aim;
	tmp = node;
	ct = 0;
	while (node && ft_strcmp(node->name, env))
	{
		tmp = node;
		node = node->next;
		ct++;
	}
	if (!node)
		ft_putstr(ft_ptrf("Var [%s] does not exist.\n", env));
	else if (node)
	{
		if (!ft_strcmp(env, "PATH"))
			g_bin = NULL;
		if (!ct)
			g_envi = cpy_list(g_envi->next, &env_node);
		else
			tmp->next = node->next;
	}
}

void	ft_cd(char **args, t_list *env)
{
	char	*goal;
	char	cur[PATH_MAX];

	if (!args[0])
		goal = ft_getenv("HOME", 0, env);
	else if (args[1])
		return (error(args[1], 3));
	else if (args[0][0] == '~')
		goal = ft_ptrf("%s/%s", ft_getenv("HOME", 0, env), args[0] + 1);
	else if (!ft_strcmp(args[0], "-"))
		goal = ft_getenv("OLDPWD", 0, env);
	else
		goal = args[0];
	if (access(goal, F_OK) == -1)
		ft_putstr("File does not exist\n");
	else if (access(goal, R_OK) == -1)
		ft_putstr("Permission denied\n");
	if (access(goal, F_OK) == -1 || access(goal, X_OK) == -1)
		return ;
	ft_set("OLDPWD", getcwd(cur, PATH_MAX), 1, env);
	chdir(goal);
	ft_set("PWD", getcwd(cur, PATH_MAX), 1, env);
}

void	ft_set(char *name, char *value, int crash, t_list *aim)
{
	t_list	*node;

	node = ft_wrd_match(name, &aim);
	if (!node)
		new_in_list(ft_ptrf("%s=%s", name, value), &aim, &env_node);
	else if (node && crash)
	{
		free(node->value);
		node->value = ft_strdup(value);
	}
	else
		ft_putendl("var already exists. Use option crash in need");
	if (!ft_strcmp(name, "PATH"))
		g_bin = list_binaries();
}

void	ft_exit(char **args, t_list *env)
{
	if (args[0])
		return (error(NULL, 0));
	ft_dellist(&g_bin);
	ft_dellist(&env);
	ft_dellist(&g_cmd_list);
	exit(-1);
}
