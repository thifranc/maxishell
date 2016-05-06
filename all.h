/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 10:58:40 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/06 20:04:29 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/syslimits.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef struct		s_list
{
	char			*name;
	char			*value;
	struct s_list	*next;
}					t_list;

t_list				*g_envi;
t_list				*g_bin;
t_list				*g_cmd_list;

t_list				*list_binaries(void);
t_list				*bin_in_list(char *path, t_list *list);
t_list				*list_env(char **env);

void				new_in_list(char *d, t_list **l, t_list *(*f)(char *d));
t_list				*env_node(char *data);
t_list				*bin_node(char *data);
t_list				*classic_node(char *data);

int					wk_dir(void);
void				ft_write_fd(char *msg, int fd);
void				do_cmd(void);
t_list				*get_cmd(char **tmp);

void				route_me(char **args);

void				exec_binary(char **args);
int					fork_me(char *path, char **args);

void				ft_set(char *name, char *value, int crash);
void				ft_unset(char *env);

void				ft_env(char **args);
void				ft_exit(char **args);
void				ft_pwd(char **args);
void				ft_cd(char **args);
void				ft_clear(char **args);
void				ft_setenv(char **args);
void				ft_unsetenv(char **args);

void				ft_dellist(t_list **list);
void				get_home(char **tab);
char				**make_tab(t_list *list);
void				error(char *cmd, int flag);
char				*ft_getenv(char *env, int flag);
t_list				*ft_wrd_match(char *word, t_list **list);

//debug func
void				print_list(t_list *list, int flag);
void				print_tab(char **lol);
#endif
