CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC =	function.c \
			main.c	\
			tri.c	\
			tri2.c	\
			tri3.c	\
			tri4.c	\


NAME = push_swap

OBJ = $(SRC:.c=.o)

$(NAME):$(OBJ)
	$(CC) $(CFLAG) $(SRC) -o pushswap

all:$(NAME)

%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf *.a
	
re: fclean all

