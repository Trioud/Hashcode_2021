NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./blablalgoritm.cpp \
	  ./src/Car.cpp \
	  ./src/Intersection.cpp \
	  ./src/Street.cpp \
	  ./src/Trafic.cpp \
	  ./src/main.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/pp
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
