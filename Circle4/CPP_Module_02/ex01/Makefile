NAME := ex01

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror

CPPFLAGS := -MMD

# RM := rm -f

SRCS = main.cpp Fixed.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

# %.o : %.cpp
# 	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJS)

.PHONY : all clean re std

all : $(NAME)

clean :
	$(RM) $(OBJS)
	$(RM) $(DEPS)
	$(RM) $(NAME)

re : clean all

std :
	@make 'CXXFLAGS := $(CXXFLAGS) -std=c++98'

-include $(DEPS)
