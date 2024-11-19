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

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_check_base(char *base)
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;
	int	n;

	if (ft_check_base(base) == 1)
		return ;
	base_length = ft_strlen(base);
	if (base_length < 2)
		return ;
	n = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		n = nbr * -1;
	}
	else
		n = nbr;
	if (n / base_length != 0)
		ft_putnbr_base(n / base_length, base);
	ft_putchar(base[nbr % base_length]);
}
