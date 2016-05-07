/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 10:24:59 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/07 14:29:42 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	printenv(t_list *aim)
{
	t_list	*node;

	node = aim;
	while (node)
	{
		ft_putendl(ft_ptrf("%s=%s", node->name, node->value));
		node = node->next;
	}
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
	if (args[0] && (env || !env))
		return (error(NULL, 0));
	else
		ft_putstr("\033[H\033[2J");
}
