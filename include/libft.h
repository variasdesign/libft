/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:18:15 by varias-c          #+#    #+#             */
/*   Updated: 2025/05/28 19:14:34 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <bits/types.h>
# include <limits.h>
# define BASE_DEC "0123456789"
# define BASE_HEX_LO "0123456789abcdef"
# define BASE_HEX_UP "0123456789ABCDEF"
# define VAR_SPECIFIERS "cspdiuxX%"
# define BUFFER_SIZE 100

typedef enum e_bool
{
	f,
	t
}	t_bool;

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	ssize_t	count;
	ssize_t	data_size;
	t_node	*head;
	t_node	*tail;
}	t_list;

// ARRAY
size_t	ft_arrlen(void **ptr);

// CHAR
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

// LIST
//t_list	*arr_to_list(t_list **lst, void *arr);
size_t	ft_lstsize(t_list *lst);
t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew_list(ssize_t data_size);
t_node	*ft_lstfind_index(t_list *list, ssize_t index);
t_node	*ft_lstlast(t_list *list);
t_node	*ft_lstnew_node(ssize_t data_size, void *content);
void	*ft_lstget_data(t_list *list, ssize_t index);
void	ft_lstadd_back(t_list *list, t_node *new_node);
void	ft_lstadd_front(t_list *list, t_node *new_node);
void	ft_lstadd_insert(t_list *list, t_node *new_node, ssize_t pos);
void	ft_lstdel_list(t_list *list, void (*del)(void *));
void	ft_lstdel_node(t_node *node, void (*del)(void *));
void	ft_lstiter(t_list *list, void (*f)(void *));

// MEMORY
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	**ft_freematrix(void **matrix, size_t count);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

// NUMBER
int		ft_abs(int n);
int		ft_atoi(const char *str);
void	*ft_intset(void *b, int c, size_t len);

// PRINT
int		ft_printf(const char *fmt, ...);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putendl_fd(char *s, int fd);
size_t	ft_putnbr_fd(int n, int fd, char *base, t_bool sign);
size_t	ft_putstr_fd(char *s, int fd);
t_bool	check_specifiers(const char *s);

// READ
char	*append_buffer_to_line(char *line, char *remaining_chars, size_t len);
char	*get_next_line(int fd);
char	*read_into_buffer(int fd, char *remaining_chars);
ssize_t	found_newline(char *remaining_chars);
t_bool	set_line(char **line, char *remaining_chars);

// STRING
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif
