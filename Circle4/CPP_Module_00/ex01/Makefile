NAME = ex01

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCS = Contact.hpp PhoneBook.hpp
SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp $(INCS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

.PHONY : all clean fclean re

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
