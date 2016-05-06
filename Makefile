# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thifranc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:24:34 by thifranc          #+#    #+#              #
#    Updated: 2016/05/06 18:57:55 by thifranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

INC = all.h

SRCS = list main ft_wrd_match debug make_lists\
	   ptr_func route_me lib builtin

SRCS:= $(addsuffix .c, $(SRCS))
OBJ = $(SRCS:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make re -C libft/
	gcc $(FLAGS) $(SRCS) libft/libft.a -o $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "erasing all binary files"

fclean: clean
	@$(RM) $(NAME)
	@make clean -C libft/
	@echo "erasing $(NAME)"

re: fclean all
	@echo "fclean + all"

.PHONY: all clean fclean re
