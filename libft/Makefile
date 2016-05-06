# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thifranc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:24:34 by thifranc          #+#    #+#              #
#    Updated: 2016/05/01 14:57:31 by thifranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c  ft_memalloc.c  ft_putchar.c  ft_strcat.c  ft_striter.c  ft_strncpy.c  ft_strtrim.c  ft_bzero.c  ft_memccpy.c  ft_putchar_fd.c   ft_strchr.c  ft_striteri.c  ft_strnequ.c  ft_tolower.c  ft_isalnum.c  ft_memchr.c  ft_putendl.c ft_strlcat.c ft_strclr.c  ft_strjoin.c  ft_strnew.c  ft_toupper.c  ft_isalpha.c  ft_memcmp.c  ft_putendl_fd.c   ft_strcmp.c  ft_strlen.c  ft_strnstr.c  ft_isascii.c  ft_memcpy.c  ft_putnbr.c  ft_strcpy.c  ft_strmap.c  ft_strrchr.c  ft_isdigit.c  ft_memdel.c  ft_putnbr_fd.c  ft_strdel.c  ft_strmapi.c  ft_strsplit.c  ft_isprint.c  ft_memmove.c  ft_putstr.c  ft_strdup.c  ft_strncat.c  ft_strstr.c  ft_itoa.c  ft_memset.c  ft_putstr_fd.c  ft_strequ.c  ft_strncmp.c  ft_strsub.c ft_lstadd.c ft_lstnew.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstdel.c ft_get_char.c ft_max.c ft_min.c ft_putnb_base.c ft_base_10.c ft_nb_len_base.c ft_higher.c ft_print_n_char.c ft_power.c ft_lower.c ft_nblen.c ft_tabnew.c ft_strdup_del.c ft_strjoin_del.c ft_gnl.c ft_ptrf.c ft_deltab.c ft_swap.c ft_realloc.c ft_write_fd.c

OBJ = ft_atoi.o  ft_memalloc.o  ft_putchar.o  ft_strcat.o  ft_striter.o  ft_strncpy.o  ft_strtrim.o  ft_bzero.o  ft_memccpy.o  ft_putchar_fd.o   ft_strchr.o  ft_striteri.o  ft_strnequ.o  ft_tolower.o  ft_isalnum.o  ft_memchr.o  ft_putendl.o  ft_strclr.o  ft_strjoin.o  ft_strnew.o  ft_toupper.o  ft_isalpha.o  ft_memcmp.o ft_putendl_fd.o   ft_strcmp.o  ft_strlcat.o ft_strlen.o  ft_strnstr.o  ft_isascii.o  ft_memcpy.o  ft_putnbr.o  ft_strcpy.o  ft_strmap.o  ft_strrchr.o  ft_isdigit.o  ft_memdel.o  ft_putnbr_fd.o  ft_strdel.o  ft_strmapi.o  ft_strsplit.o  ft_isprint.o  ft_memmove.o  ft_putstr.o  ft_strdup.o  ft_strncat.o  ft_strstr.o  ft_itoa.o  ft_memset.o  ft_putstr_fd.o  ft_strequ.o  ft_strncmp.o ft_strsub.o ft_lstadd.o ft_lstnew.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstdel.o ft_get_char.o ft_max.o ft_min.o ft_putnb_base.o ft_base_10.o ft_nb_len_base.o ft_higher.o ft_print_n_char.o ft_power.o ft_lower.o ft_nblen.o ft_tabnew.o ft_strdup_del.o ft_strjoin_del.o ft_gnl.o ft_ptrf.o ft_deltab.o ft_swap.o ft_realloc.o ft_write_fd.o
all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	make clean

clean :
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)
re : fclean all
