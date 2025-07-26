/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:15:48 by varias-c          #+#    #+#             */
/*   Updated: 2025/07/26 17:21:34 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_error(char *msg, char *err, int exit_code)
{
	if (!msg)
		ft_printf(2, "%s\n", err);
	else if (!err)
		ft_printf(2, msg);
	else
		ft_printf(2, msg, err);
	if (exit_code)
		exit(exit_code);
}

