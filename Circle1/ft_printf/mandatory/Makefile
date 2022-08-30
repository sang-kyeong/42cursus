# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 23:36:35 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/22 23:49:13 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRC_DIR := srcs
SRCS := main.c put_format.c put_format2.c build_number.c

OBJ_DIR := objs
OBJS := $(SRCS:.c=.o)

LIBFT := ft
LIBFT_DIR := libft

CC := cc
CFLAGS := -Wall -Wextra -Werror -c

AR := ar
ARFLAGS := xvfc

.c.o:
	$(CC) $(CFLAGS) $^ -I (LIBFT_DIR)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -f $(OBJS)

flcean : clean
	rm -f $(NAME)

re : fclean re