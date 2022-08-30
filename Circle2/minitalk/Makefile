# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 10:12:59 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/11 11:39:05 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mknitalk

MANDATORY_DIR = mandatory
BONUS_DIR = bonus

$(NAME) :
	@make -C$(MANDATORY_DIR)

.PHONY : $(NAME) all clean fclean re bonus

all : $(NAME)

clean :
	@make -C$(MANDATORY_DIR) clean
	@make -C$(BONUS_DIR) clean

fclean : clean
	@make -C$(MANDATORY_DIR) fclean
	@make -C$(BONUS_DIR) fclean

re : fclean all

bonus :
	@make -C$(BONUS_DIR)