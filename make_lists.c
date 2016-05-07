/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 18:56:47 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/07 10:04:03 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*list_env(char **env)
{
	int		i;
	t_list	*out;

	i = 0;
	out = NULL;
	while (env[i])
	{
		new_in_list(env[i], &out, &env_node);
		i++;
	}
	return (out);
}

t_list	*bin_in_list(char *path, t_list *list)
{
	struct dirent	*d;
	DIR				*dir;
	char			*total;

	if ((dir = opendir(path)) != 0)
	{
		while ((d = readdir(dir)) != NULL)
		{
			total = ft_ptrf("%s/%s", path, d->d_name);
			if (access(total, F_OK) != -1 && access(total, X_OK) != -1)
				new_in_list(total, &list, &bin_node);
			free(total);
		}
	}
	else
	{
		ft_putstr("PATH var is corrupted. A dir couldn't open\n");
		return (NULL);
	}
	closedir(dir);
	return (list);
}

t_list	*list_binaries(void)
{
	char			**paths;
	char			*path;
	int				i;
	t_list			*list;

	i = 0;
	paths = NULL;
	list = NULL;
	if ((path = ft_getenv("PATH", 1, g_envi)) == NULL)
		return (NULL);
	path += ft_get_char(path, '=') + 1;
	paths = ft_strsplit(path, ':');
	while (paths[i])
		list = bin_in_list(paths[i++], list);
	ft_deltab((void**)paths);
	return (list);
}
