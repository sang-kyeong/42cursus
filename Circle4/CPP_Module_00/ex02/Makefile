NAME := ex02

CXX := g++
CXXFLAGS := -Wall -Wextra -Werror

CPPFLAGS := -MMD

CC := 
CFLAGS :=

# RM := rm -f

SRCS = test.cpp Account.cpp
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
	@make 'CXXFLAGS := $(CXXFLAGS) -std=c++98 -pedantic'

-include $(DEPS)
