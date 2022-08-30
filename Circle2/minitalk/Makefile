# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 10:12:59 by sangkkim          #+#    #+#              #
#    Updated: 2022/08/30 15:23:49 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
BONUS_SERVER_SRCS = server_bonus.c utils1_bonus.c utils2_bonus.c
BONUS_CLIENT_SRCS = client_bonus.c utils1_bonus.c utils2_bonus.c
MANDATORY_SERVER_SRCS = server.c
MANDATORY_CLIENT_SRCS = client.c

INC_DIR = incs
ifeq (BONUS, true)
INCS = minitalk_bonus.h utils_bonus.h
else
INCS = 
endif

OBJ_DIR = objs
ifeq ($(BONUS),true)
SERVER_OBJS = $(BONUS_SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(BONUS_CLIENT_SRCS:.c=.o)
else
SERVER_OBJS = $(MANDATORY_SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(MANDATORY_CLIENT_SRCS:.c=.o)
endif

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(addprefix $(INC_DIR)/, $(INCS))
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INC_DIR)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : $(addprefix $(OBJ_DIR)/, $(SERVER_OBJS))
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT) : $(addprefix $(OBJ_DIR)/, $(CLIENT_OBJS))
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : $(NAME) $(SERVER) $(CLIENT) all clean fclean re bonus

all : $(NAME)

clean :
	rm -f $(addprefix $(OBJ_DIR)/, $(BONUS_SERVER_SRCS:.c=.o))
	rm -f $(addprefix $(OBJ_DIR)/, $(BONUS_CLIENT_SRCS:.c=.o))
	rm -f $(addprefix $(OBJ_DIR)/, $(MANDATORY_SERVER_SRCS:.c=.o))
	rm -f $(addprefix $(OBJ_DIR)/, $(MANDATORY_CLIENT_SRCS:.c=.o))

fclean : clean
	rm -f server client

re : fclean all

bonus :
	make BONUS=true all
