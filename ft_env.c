/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 14:07:18 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/07 14:45:46 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		get_opt(char **args, int *i)
{
	int		k;
	int		opt;

	opt = 0;
	while (args[*i] && args[*i][0] == '-')
	{
		k = 1;
		while (ft_get_char("uih", args[*i][k]) != -1)
		{
			if (args[*i][k] == 'i')
				opt |= I_OPT;
			if (args[*i][k] == 'u')
				opt |= U_OPT;
			if (args[*i][k] == 'h')
				opt |= H_OPT;
			k++;
		}
		(*i)++;
	}
	return (opt);
}

void	ft_env(char **args, t_list *env)
{
	int		i;
	int		ret;
	int		opt;
	t_list	*mirror;

	i = 0;
	opt = get_opt(args, &i);
	if (opt & I_OPT)
		mirror = NULL;
	else
		mirror = cpy_list(env, &env_node);
	while (args[i])
	{
		if (opt & U_OPT)
			ft_unset(args[i], mirror);
		else if ((ret = ft_get_char(args[i], '=')) != -1)
		{
			args[i][ret] = '\0';
			ft_set(args[i], args[i] + ret + 1, 1, mirror);
		}
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

