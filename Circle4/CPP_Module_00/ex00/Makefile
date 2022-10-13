NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
