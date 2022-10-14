NAME = ex01

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

INCS = Zombie.hpp
SRCS = main.cpp Zombie.cpp zombieHorde.cpp

$(NAME) : $(SRCS) $(INCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
