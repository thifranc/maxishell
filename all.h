/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 10:58:40 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/09 14:36:42 by thifranc         ###   ########.fr       */
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
void				do_cmd(t_list *aim);
t_list				*get_cmd(char **tmp);

void				route_me(char **args, t_list *aim);

void				exec_binary(char **args, t_list *aim);
int					fork_me(char *path, char **args, t_list *aim);

void				ft_set(char *name, char *value, int crash, t_list *aim);
void				ft_unset(char *env, t_list *aim);

void				ft_env(char **args, t_list *env);
void				ft_exit(char **args, t_list *env);
void				ft_pwd(char **args, t_list *env);
void				ft_cd(char **args, t_list *env);
void				ft_clear(char **args, t_list *env);
void				ft_setenv(char **args, t_list *env);
void				ft_unsetenv(char **args, t_list *env);

void				ft_dellist(t_list **list);
void				del_node(t_list **list);
t_list				*cpy_list(t_list *list, t_list *(*f)(char *data));
void				get_home(char **tab, t_list *aim);
char				**make_tab(t_list *list);
void				error(char *cmd, int flag);
char				*ft_getenv(char *env, int flag, t_list *aim);
t_list				*ft_wrd_match(char *word, t_list **list);

void				printenv(t_list *aim);
void				print_list(t_list *list, int flag);
void				print_tab(char **lol);
int					list_size(t_list *list);
#endif
