/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:20:08 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/02 18:20:39 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_del(char const *s1, char const *s2, int del)
{
	char	*out;
	int		i;
	int		i2;

	if (!(out = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	out = ft_strcpy(out, s1);
	i = ft_strlen(s1);
	i2 = 0;
	while (s2 && s2[i2])
		out[i++] = s2[i2++];
	out[i] = '\0';
	if (del == 2)
	{
		free((void*)s1);
		free((void*)s2);
	}
	if (del == -1)
		free((void*)s1);
	if (del == 1)
		free((void*)s2);
	return (out);
}
