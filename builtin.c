/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 14:15:20 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/07 10:07:27 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	ft_unset(char *env, t_list *aim)
{
	t_list	*node;
	t_list	*tmp;

	node = aim;
	tmp = node;
	while (node && ft_strcmp(node->name, env))
	{
		tmp = node;
		node = node->next;
	}
	if (!node)
		ft_putstr(ft_ptrf("Var [%s] does not exist.\n", env));
	else if (node)
	{
		if (!ft_strcmp(env, "PATH"))
			g_bin = NULL;
		tmp->next = node->next;
		//ft_memdel((void**)&node); double free des fois
	}
}

void	ft_cd(char **args)
{
	char	*goal;
	char	cur[PATH_MAX];

	if (!args[0])
		goal = ft_getenv("HOME", 0, g_envi);
	else if (args[1])
		return (error(args[1], 3));
	else if (args[0][0] == '~')
		goal = ft_ptrf("%s/%s", ft_getenv("HOME", 0, g_envi), args[0] + 1);
	else if (!ft_strcmp(args[0], "-"))
		goal = ft_getenv("OLDPWD", 0, g_envi);
	else
		goal = args[0];
	if (access(goal, F_OK) == -1)
		ft_putstr("File does not exist\n");
	else if (access(goal, R_OK) == -1)
		ft_putstr("Permission denied\n");
	if (access(goal, F_OK) == -1 || access(goal, X_OK) == -1)
		return ;
	ft_set("OLDPWD", getcwd(cur, PATH_MAX), 1, g_envi);
	chdir(goal);
	ft_set("PWD", getcwd(cur, PATH_MAX), 1, g_envi);
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
}

void	ft_exit(char **args)
{
	if (args[0])
		return (error(NULL, 0));
	ft_dellist(&g_bin);
	ft_dellist(&g_envi);
	ft_dellist(&g_cmd_list);
	exit(-1);
}