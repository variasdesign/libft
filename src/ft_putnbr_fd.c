/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:05:56 by varias-c          #+#    #+#             */
/*   Updated: 2024/11/19 20:36:39 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	ft_putnbr_base(int nbr, char *base, int fd)
{
	int		base_length;
	long	n;

	if (check_base(base) == 1)
		return ;
	base_length = ft_strlen(base);
	if (base_length < 2)
		return ;
	n = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		n = (long) nbr * -1;
	}
	else
		n = nbr;
	if (n / base_length != 0)
		ft_putnbr_base(n / base_length, base, fd);
	ft_putchar_fd(base[n % base_length], fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr_base(n, "0123456789", fd);
}
/**/
/* int	main (int argc, char **argv) */
/* { */
/* 	if (argc != 2) */
/* 		return (1); */
/* 	ft_putnbr_fd(atoi(argv[1]), 2); */
/* 	return (0); */
/* } */
