# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 14:26:23 by sangkkim          #+#    #+#              #
#    Updated: 2022/10/11 13:20:55 by sangkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = main.c get_input.c init_sim.c \
	   philo_main.c philo_action.c
INCS = philo.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(SRCS) $(INCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

.PHONY : all clean fclean re

all : $(NAME)

clean :

fclean : clean
	rm -f $(NAME)

re : fclean all
