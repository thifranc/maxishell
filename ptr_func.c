/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 10:24:59 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/07 10:40:24 by thifranc         ###   ########.fr       */
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

void	ft_env(char **args, t_list *env)
{
	int		i;
	int		ret;
	t_list	*mirror;
//pb segfault
	i = 0;
//	dprintf(1, "lndr\n");
	mirror = cpy_list(env, &env_node);
//	dprintf(1, "tg\n");
	while (args[i] && (ret = ft_get_char(args[i], '=')) != -1)
	{
//	dprintf(1, "lol1\n");
		args[i][ret] = '\0';
	dprintf(1, "lol2\n");
		ft_set(args[i], args[i] + ret + 1, 1, mirror);
	dprintf(1, "lol3\n");
		i++;
	}
	dprintf(1, "lol4\n");
	if (!args[i])
		printenv(mirror);
	else
	{
	dprintf(1, "lol5\n");
		get_home(args + i, mirror);
	dprintf(1, "lol6\n");
		route_me(args + i, mirror);
	dprintf(1, "lol7\n");
	}
	dprintf(1, "lol8\n");
	ft_dellist(&mirror);
	dprintf(1, "lol9\n");
}

void	ft_setenv(char **args, t_list *env)
{
	if (!args[0] || !args[1] || !args[2])
		return (error("(null)", 2));
	if (args[3])
		return (error(args[3], 3));
	ft_set(args[0], args[1], ft_atoi(args[2]), env);
}

void	ft_unsetenv(char **args, t_list *env)
{
	int		r;

	r = 0;
	if (!args[0])
		return (error("(null)", 7));
	while (args[r])
	{
		ft_unset(args[r], env);
		r++;
	}
}

void	ft_clear(char **args, t_list *env)
{
	if (args[0] || !env)
		return (error(NULL, 0));
	else
		ft_putstr("\033[H\033[2J");
}
