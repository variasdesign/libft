NAME = libft.a

CC				= clang
CFLAGS			= -Wextra -Wall -Werror
CFLAGS			+= -std=c99
CFLAGS			+= -ggdb3
# CFLAGS			+= -fsanitize=address
RM				= rm -rf

BASE_DIR		= ./src
BUILD_DIR		= ./.build

HEADERS			= -I ./include

ARRAY_DIR		= $(BASE_DIR)/array/
CHAR_DIR		= $(BASE_DIR)/char/
LIST_DIR		= $(BASE_DIR)/list/
MEM_DIR			= $(BASE_DIR)/memory/
NUM_DIR			= $(BASE_DIR)/number/
PRINT_DIR		= $(BASE_DIR)/print/
READ_DIR		= $(BASE_DIR)/read/
STR_DIR			= $(BASE_DIR)/string/

ARRAY_SRCS		= $(addprefix $(ARRAY_DIR),	\
					ft_arrlen.c			\
					)

CHAR_SRCS		= $(addprefix $(CHAR_DIR),		\
					ft_isalnum.c				\
					ft_isalpha.c				\
					ft_isascii.c				\
					ft_isdigit.c				\
					ft_isprint.c				\
					ft_isspace.c				\
					ft_tolower.c				\
					ft_toupper.c				\
					)
					
MEM_SRCS		= $(addprefix $(MEM_DIR),		\
					ft_bzero.c					\
					ft_calloc.c					\
					ft_freematrix.c				\
					ft_memchr.c					\
					ft_memcmp.c					\
					ft_memcpy.c					\
					ft_memmove.c				\
					ft_memset.c					\
					)

NUM_SRCS		= $(addprefix $(NUM_DIR),		\
					ft_abs.c					\
					ft_atoi.c					\
					ft_intset.c					\
					)

PRINT_SRCS		= $(addprefix $(PRINT_DIR),		\
					ft_printf.c					\
					ft_printf_aux.c				\
					ft_putchar_fd.c				\
					ft_putendl_fd.c				\
					ft_putnbr_fd.c				\
					ft_putstr_fd.c				\
					)

READ_SRCS		= $(addprefix $(READ_DIR),		\
					get_next_line.c				\
					)

STR_SRCS		= $(addprefix $(STR_DIR),		\
					ft_itoa.c					\
					ft_split.c					\
					ft_strchr.c					\
					ft_strdup.c					\
					ft_striteri.c				\
					ft_strjoin.c				\
					ft_strlcat.c				\
					ft_strlcpy.c				\
					ft_strlen.c					\
					ft_strmapi.c				\
					ft_strncmp.c				\
					ft_strnstr.c				\
					ft_strrchr.c				\
					ft_strtrim.c				\
					ft_substr.c					\
					)

BASE_SRCS		=	$(ARRAY_SRCS)	\
					$(CHAR_SRCS)	\
					$(LIST_SRCS)	\
					$(MEM_SRCS)		\
					$(NUM_SRCS)		\
					$(PRINT_SRCS)	\
					$(READ_SRCS)	\
					$(STR_SRCS)

LIST_SRCS		=	$(addprefix $(LIST_DIR),	\
					ft_lstadd.c					\
					ft_lstdel.c					\
					ft_lstdel_2.c				\
					ft_lstfind.c				\
					ft_lstget.c					\
					ft_lstiter.c				\
					ft_lstlast.c				\
					ft_lstmap.c					\
					ft_lstnew.c					\
					ft_lstsize.c				\
					)							\

BONUS_SRCS		= 	$(LIST_SRCS)	\
					$(BASE_SRCS)



BASE_OBJS		= $(BASE_SRCS:$(BASE_DIR)/%.c=$(BUILD_DIR)/%.o)
BONUS_OBJS		= $(BONUS_SRCS:$(BASE_DIR)/%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(BASE_OBJS)
	@echo "Assembling library..."
	@ar r $(NAME) $(BASE_OBJS)
	@echo "Done! :D"

bonus: $(BONUS_OBJS)
	@echo "Assembling library with bonus..."
	@ar r $(NAME) $(BONUS_OBJS)
	@echo "libft bonus done!"

$(BUILD_DIR)/%.o: $(BASE_DIR)/%.c
	@echo "Compiling $@..."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@

clean:
	@echo "Cleaning objects..."
	@$(RM) $(BASE_OBJS) $(BONUS_OBJS) $(BASE_TARGET) $(BONUS_TARGET)
	@echo "Done! :D"

fclean: clean
	@echo "Cleaning all..."
	@$(RM) $(BUILD_DIR)
	@$(RM) $(NAME)
	@echo "Done! :D"

re: fclean all

.PHONY: all clean fclean re
