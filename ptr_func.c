/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 10:24:59 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/07 10:08:51 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	printenv(t_list * aim)
{
	t_list	*node;

	node = aim;
	while (node)
	{
		ft_putendl(ft_ptrf("%s=%s", node->name, node->value));
		node = node->next;
	}
}

void	ft_env(char **args)
{
	int		i;
	int		ret;
	t_list	*mirror;

	i = 0;
	mirror = cpy_list(g_envi, &env_node);
	while (args[i] && (ret = ft_get_char(args[i], '=')) != -1)
	{
		args[i][ret] = '\0';
		ft_set(args[i], args[i] + ret + 1, 1, mirror);
		i++;
	}
	if (!args[i])
		printenv(mirror);
	else
	{
		get_home(args + i, mirror);
		route_me(args + i, mirror);
	}
	ft_dellist(&mirror);
}

void	ft_setenv(char **args)
{
	if (!args[0] || !args[1] || !args[2])
		return (error("(null)", 2));
	if (args[3])
		return (error(args[3], 3));
	ft_set(args[0], args[1], ft_atoi(args[2]), g_envi);
}

void	ft_unsetenv(char **args)
{
	int		r;

	r = 0;
	if (!args[0])
		return (error("(null)", 7));
	while (args[r])
	{
		ft_unset(args[r], g_envi);
		r++;
	}
}

void	ft_clear(char **args)
{
	if (args[0])
		return (error(NULL, 0));
	else
		ft_putstr("\033[H\033[2J");
}
