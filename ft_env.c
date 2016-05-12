/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 14:07:18 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/12 14:40:51 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	update_env(char **args, t_list **aim, int *i)
{
	int		ret;

	*i = 0;
	while (args[*i] && ((!ft_strcmp("-u", args[*i]))
		|| !ft_strcmp("--unset", args[*i]) || ft_get_char(args[*i], '=') != -1
			|| !ft_strcmp("-i", args[*i])))
	{
		if (args[*i + 1] && (!ft_strcmp("-u", args[*i]) || !ft_strcmp("--unset", args[*i])))
			ft_unset(args[++(*i)], *aim);
		if ((ret = ft_get_char(args[*i], '=')) != -1)
		{
			args[*i][ret] = '\0';
			if (!(*aim))
				new_in_list(ft_ptrf("%s=%s", args[*i],
							args[*i] + ret + 1), aim, &env_node);
			else
				ft_set(args[*i], args[*i] + ret + 1, 1, *aim);
		}
		(*i)++;
	}
}

void	ft_env(char **args, t_list *env)
{
	int		i;
	t_list	*mirror;

	i = 0;
	while (args[i] && ft_strcmp(args[i], "-i"))
		i++;
	if (!args[i])
		mirror = cpy_list(env, &env_node);
	else
		mirror = NULL;
	update_env(args, &mirror, &i);
	if (!args[i])
		printenv(mirror);
	else
	{
		get_home(args + i, mirror);
		route_me(args + i, mirror);
	}
	ft_dellist(&mirror);
}
