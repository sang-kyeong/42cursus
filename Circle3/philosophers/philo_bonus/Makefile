# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 22:22:10 by sangkkim          #+#    #+#              #
#    Updated: 2022/08/27 18:04:56 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo_bonus

SRCS := main_bonus.c init_sim_bonus.c utils1_bonus.c

INCS := philo_bonus.h

CC := cc
CFLAGS := -Wall -Wextra -Werror

$(NAME) : $(SRCS) $(INCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

.PHONY : all clean fclean re

all : $(NAME)

clean :

fclean : clean
	rm -f $(NAME)

re : fclean all
