SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -g -Wall -Werror -Wextra 
NAME = pipex

all:		$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@
clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean re fclean