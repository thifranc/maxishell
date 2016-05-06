/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrd_match.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 13:58:15 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/06 14:20:04 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*ft_wrd_match(char *word, t_list **list)
{
	if (!(*list))
		return (NULL);
	else if (!ft_strcmp((*list)->name, word))
		return (*list);
	else
		return (ft_wrd_match(word, &(*list)->next));
}
