# Makefile

# Makefile

CC = gcc

RM = rm -f

NAME = sokoban

SRCS = 	main.c \
		srcs/*.c

OBJS = $(SRCS: .c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
