#include "../libft.h"

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "Please enter a single argument\n", ft_strlen("Please enter a single argument\n"));
		return (1);
	}
	write(1, "Testing ft_putchar_fd\n", ft_strlen("Testing ft_putchar_fd\n"));
	ft_putchar_fd(*argv[1], 1);
	write(1, "\n", 1);
	write(1, "Testing ft_putstr_fd\n", ft_strlen("Testing ft_putstr_fd\n"));
	ft_putstr_fd(argv[1], 1);
	write(1, "\n", 1);
	write(1, "Testing ft_putendl_fd\n", ft_strlen("Testing ft_putendl_fd\n"));
	ft_putendl_fd(argv[1], 1);
	return (0);
}
