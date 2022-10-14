NAME = test

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

INCS = Account.hpp
SRCS = test.cpp Account.cpp

$(NAME) : $(SRCS) $(INCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
