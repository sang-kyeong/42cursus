# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 13:15:15 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/29 23:50:51 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

SRCS := main.c ft_execve.c

INCS :=

LIBFT := libft

CC := cc
CFLAGS := -Wall -Wextra -Werror

$(NAME) : $(SRCS) $(INCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SRCS) -I libft -L libft -l ft

.PHONY : $(LIBFT) all clean fclean re

$(LIBFT) :
	make -C libft

all : $(NAME)

clean :
	make -C libft fclean

fclean : clean
	rm -f $(NAME)

re : fclean all
