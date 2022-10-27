NAME = ex00

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCS = Zombie.hpp
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
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
