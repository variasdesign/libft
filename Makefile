SRCS	=	array/ft_arrlen.c \
			char/ft_isalnum.c \
			char/ft_isalpha.c \
			char/ft_isascii.c \
			char/ft_isdigit.c \
			char/ft_isprint.c \
			char/ft_isspace.c \
			char/ft_tolower.c \
			char/ft_toupper.c \
			memory/ft_bzero.c \
			memory/ft_calloc.c \
			memory/ft_freematrix.c \
			memory/ft_memchr.c \
			memory/ft_memcmp.c \
			memory/ft_memcpy.c \
			memory/ft_memmove.c \
			memory/ft_memset.c \
			number/ft_abs.c \
			number/ft_atoi.c \
			number/ft_intset.c \
			print/ft_printf.c \
			print/ft_printf_aux.c \
			print/ft_putchar_fd.c \
			print/ft_putendl_fd.c \
			print/ft_putnbr_fd.c \
			print/ft_putstr_fd.c \
			read/get_next_line.c \
			string/ft_itoa.c \
			string/ft_split.c \
			string/ft_strchr.c \
			string/ft_strdup.c \
			string/ft_striteri.c \
			string/ft_strjoin.c \
			string/ft_strlcat.c \
			string/ft_strlcpy.c \
			string/ft_strlen.c \
			string/ft_strmapi.c \
			string/ft_strncmp.c \
			string/ft_strnstr.c \
			string/ft_strrchr.c \
			string/ft_strtrim.c \
			string/ft_substr.c

SRCS_BONUS	=	list/ft_lstadd.c \
				list/ft_lstclear.c \
				list/ft_lstdel_one.c \
				list/ft_lstfind.c \
				list/ft_lstget.c \
				list/ft_lstiter.c \
				list/ft_lstlast.c \
				list/ft_lstmap.c \
				list/ft_lstnew.c \
				list/ft_lstsize.c \
				${SRCS}

NAME = libft.a

SRC_DIR := src

OBJ := $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)
OBJ_BONUS_PREFIXED = $(addprefix $(OBJ_DIR), $(OBJ_BONUS))

CC = clang

CC_FLAGS = -Wall -Wextra -Werror -Iinclude

%.o : $(SRC_DIR)/%.c
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ)
	@echo "libft done!"

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ_BONUS_PREFIXED)
	@ar r $(NAME) $(OBJ_BONUS_PREFIXED)
	@echo "libft bonus done!"
