# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 21:16:47 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/10 22:07:44 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC_DIR = incs
INCS = format_bonus.h

SRC_DIR = srcs
SRCS = ft_printf_bonus.c \
	get_format_bonus.c check_format_bonus.c \
	format_utils_bonus.c \
	put_c_bonus.c put_s_bonus.c put_p_bonus.c \
	put_d_bonus.c put_u_bonus.c put_x_bonus.c

OBJ_DIR = objs
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ../libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(addprefix $(OBJ_DIR)/,$(OBJS))
	ar rcus $(NAME) $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(addprefix $(INC_DIR)/,$(INCS)) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR) -I $(LIBFT_DIR)
#-L $(LIBFT_DIR) -l ft

$(LIBFT) :
	make -C libft