/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 10:24:59 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/06 19:01:52 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	printenv(void)
{
	t_list	*node;

	node = g_envi;
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

	i = 0;
	while (args[i] && (ret = ft_get_char(args[i], '=')) != -1)
	{
		args[i][ret] = '\0';
		ft_set(args[i], args[i] + ret + 1, 1);
		i++;
	}
	if (args[i])
	{
		get_home(args + i);
		route_me(args + i);
	}
	else
		printenv();
	while (--i > 0)//pb efface if binaire fork
		ft_unset(args[i]);
}

void	ft_setenv(char **args)
{
	if (!args[0] || !args[1] || !args[2])
		return (error("(null)", 2));
	if (args[3])
		return (error(args[3], 3));
	ft_set(args[0], args[1], ft_atoi(args[2]));
}

void	ft_unsetenv(char **args)
{
	int		r;

	r = 0;
	if (!args[0])
		return (error("(null)", 7));
	while (args[r])
	{
		ft_unset(args[r]);
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
