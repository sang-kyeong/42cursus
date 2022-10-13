NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror

INCS = PhoneBook.hpp Contact.hpp
SRCS = main.cpp

$(NAME) : $(SRCS) $(INCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
