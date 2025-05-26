/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:34:43 by varias-c          #+#    #+#             */
/*   Updated: 2025/02/19 19:03:59 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_pointer(void *ptr)
{
	const size_t	ptr_nbr = (size_t) ptr;

	if (ptr)
		return (ft_putstr_fd("0x", 1)
			+ ft_putnbr_fd(ptr_nbr, 1, BASE_HEX_LO, f));
	return (ft_putstr_fd("(nil)", 1));
}

static ssize_t	print_number(va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1, BASE_DEC, t));
	else if (c == 'u')
		return (ft_putnbr_fd(va_arg(ap, int), 1, BASE_DEC, f));
	else if (c == 'x')
		return (ft_putnbr_fd(va_arg(ap, int), 1, BASE_HEX_LO, f));
	else if (c == 'X')
		return (ft_putnbr_fd(va_arg(ap, int), 1, BASE_HEX_UP, f));
	else if (c == 'p')
		return (print_pointer(va_arg(ap, void *)));
	return (-1);
}

static ssize_t	print_string(va_list ap)
{
	const char	*str = va_arg(ap, char *);

	if (str)
		return (ft_putstr_fd((char *)str, 1));
	return (ft_putstr_fd("(null)", 1));
}

static size_t	print_variable(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	else if (c == 's')
		return (print_string(ap));
	else if (c == 'd' || c == 'i' || c == 'p'
		|| c == 'u' || c == 'x' || c == 'X')
		return (print_number(ap, c));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	count;

	if (!fmt || !(check_specifiers(fmt)))
		return (-1);
	va_start(ap, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt != '%')
			count += ft_putchar_fd(*fmt++, 1);
		else if (*++fmt)
			count += print_variable(ap, *fmt++);
		else
			return (-1);
	}
	va_end(ap);
	return (count);
}
