/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:32:45 by varias-c          #+#    #+#             */
/*   Updated: 2024/11/14 19:35:31 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	nbrlen(int n, int count)
{
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char *putnbr(int n, int count, int pos, char *str)
{
	while (pos < count)
	{
		str[count - 2] = (n % 10) + 48;
		n = n / 10;
		count--;
	}
	return (str);
}

char *ft_itoa(int n)
{
	char	*str;
	int		magnitude;

	magnitude = 1;
	magnitude = nbrlen(n, magnitude);
	str = ft_calloc(magnitude, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str = putnbr(-n, magnitude, 2, str); 
	}
	else
		str = putnbr(n, magnitude, 1, str);	
	str[magnitude - 1] = '\0';
	return (str);
}

int main(int argc, char **argv)
{
	char *str;

	if (argc != 2)
	{
		printf("Please input a single argument");
		return (1);
	}
	str = ft_itoa(ft_atoi(argv[1]));
	printf("%s\n", str);
	return (0);
}
