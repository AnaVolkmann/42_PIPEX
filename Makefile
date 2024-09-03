SRCS = main.c utils.c error.c pipex.c
OBJS = $(SRCS:.c=.o)
CC = cc
LIBFT = libft
LIBFTA = libft/libft.a
RM = rm -f
CFLAGS = -g -Wall -Werror -Wextra
NAME = pipex

all:		$(NAME)

$(NAME):	$(LIBFTA) $(OBJS)	
			$(CC)  $(CFLAGS) $(OBJS) $(LIBFTA) -o $(NAME)
			@echo "\033[032mPIPEX COMPILATION SUCCEEDED\033[0m"
	
$(LIBFTA): $(LIBFT)
			make -s -C $(LIBFT)

clean:
			$(RM) $(OBJS)
			make clean -s -C $(LIBFT)
			@echo "\033[38;5;208mOBJECTS DELETED\033[0m"

fclean:			clean
			$(RM) $(NAME)
			make fclean -s -C $(LIBFT)
			@echo "\033[031mPROGRAM DELETED\033[0m"

re:			fclean all

.PHONY:		all clean re fclean

.SILENT: