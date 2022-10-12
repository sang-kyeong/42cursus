# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 14:26:23 by sangkkim          #+#    #+#              #
#    Updated: 2022/10/12 11:01:09 by sangkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCS = philo.h
SRCS = main.c get_input.c init_sim.c philo_main.c philo_action.c utils.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

.o : .c $(INCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
