NAME := philo

CC := cc
CFLAGS := #-Wall -Wextra -Werror

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror

CPPFLAGS := -MMD

# RM := rm -f

SRCS := main.c get_condition.c init_simulation.c monitor_main.c util_time.c \
	philo_main.c philo_echo.c
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

# %.o : %.c
# 	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

# %.o : %.cpp
# 	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

.PHONY : all clean fclean re

all : $(NAME)

clean :
	$(RM) $(OBJS)
	$(RM) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

-include $(DEPS)
