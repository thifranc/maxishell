/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:44:29 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/06 17:18:12 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		list_size(t_list *list)
{
	if (!list)
		return (0);
	else
		return (1 + list_size(list->next));
}

char	*ft_getenv(char *env, int flag)
{
	t_list	*cur;

	cur = g_envi;
	while (cur)
	{
		if (flag && !ft_strcmp(env, cur->name))
			return (ft_ptrf("%s=%s", cur->name, cur->value));
		if (!flag && !ft_strcmp(env, cur->name))
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}

void	ft_dellist(t_list **list)
{
	if (*list)
	{
		ft_dellist(&(*list)->next);
		free((*list)->name);
		free((*list)->value);
		free((*list)->next);
		free(*list);
		*list = NULL;
	}
}

char	**make_tab(t_list *list)
{
	char	**out;
	t_list	*tmp;
	int		i;

	tmp = list;
	i = list_size(tmp);
	if (!(out = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	tmp = list;
	out[i] = NULL;
	while (tmp)
	{
		i--;
		out[i] = ft_ptrf("%s=%s", tmp->name, tmp->value);
		tmp = tmp->next;
	}
	return (out);
}
