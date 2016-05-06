/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 14:25:59 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/06 19:40:51 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*classic_node(char *data)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->name = ft_strdup(data);
	new->value = ft_strdup("lol");
	new->next = NULL;
	return (new);
}

t_list	*env_node(char *data)
{
	t_list	*new;
	int		ret;

	ret = ft_get_char(data, '=');
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (ret != -1)
	{
		data[ret] = '\0';
		new->name = ft_strdup(data);
		new->value = ft_strdup(data + ret + 1);
		new->next = NULL;
		return (new);
	}
	ft_putstr("PROBLEME FT_GET_CHAR DS ENV_NODE LIST.C\n");
	return (NULL);
}

void	new_in_list(char *data, t_list **list, t_list *(*f)(char *data))
{
	if (!(*list))
		(*list) = f(data);
	else if (!(*list)->next)
		(*list)->next = f(data);
	else
		new_in_list(data, &(*list)->next, f);
}

t_list	*bin_node(char *data)
{
	t_list	*new;
	int		ret;

	ret = ft_strlen(data);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (ret != 0)
	{
		new->value = ft_strdup(data);
		while (data[ret] != '/')
			ret--;
		new->name = ft_strdup(data + ret + 1);
		new->next = NULL;
		return (new);
	}
	ft_putstr("PROBLEME FT_GET_CHAR DS BIN_NODE LIST.C\n");
	return (NULL);
}
