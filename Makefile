CC=cc
CFLAGS=-Wall -Wextra -Werror -g
OBJECTS=main.o memory.o ascii.o put.o string.o

all : $(OBJECTS)
	$(CC) -o test $(OBJECTS)
main.o : main.c libft.h
	$(CC) $(CFLAGS) main.c
memory.o : ft_bzero.c ft_memset.c libft.h
	$(CC) $(CFLAGS) ft_bzero.c ft_memset.c
ascii.o : ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c libft.h
	$(CC) $(CFLAGS) ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c
put.o : ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c libft.h
	$(CC) $(CFLAGS) ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c
string.o : ft_strlen.c libft.h
	$(CC) $(CFLAGS) ft_strlen.c
clean :
	rm test $(OBJECTS)
