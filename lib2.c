/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 14:03:46 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/07 14:03:55 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return (0);
	else
		return (1 + list_size(begin_list->next));
}

void	del_node(t_list **list)
{
	free((*list)->name);
	free((*list)->value);
	free((*list)->next);
	free(*list);
}

void	ft_dellist(t_list **list)
{
	if (*list)
	{
		ft_dellist(&(*list)->next);
		del_node(&(*list));
		*list = NULL;
	}
}
