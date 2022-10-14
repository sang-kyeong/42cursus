NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

INCS = Contact.hpp PhoneBook.hpp
SRCS = main.cpp Contact.cpp PhoneBook.cpp

$(NAME) : $(SRCS) $(INCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
