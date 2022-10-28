NAME = ex00

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCS = Fixed.hpp
SRCS = main.cpp Fixed.cpp
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
