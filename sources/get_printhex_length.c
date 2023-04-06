/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printhex_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:26:39 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/06 17:17:26 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	hex_length(unsigned int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		length++;
		n = n / 16;
	}
	return (length);
}

void	print_hex(unsigned int n, const char mychar)
{
	if (n < 10)
	{
		ft_put_char(n + '0');
	}
	else if (n >= 10 && n < 16)
	{
		if (mychar == 'x')
			ft_put_char(n - 10 + 'a');
		if (mychar == 'X')
			ft_put_char(n - 10 + 'A');
	}
	else if (n >= 16)
	{
		print_hex(n / 16, mychar);
		print_hex(n % 16, mychar);
	}
}

int	get_printhex_length(unsigned int n, const char mychar)
{
	int	sign;

	sign = 0;
	if (n == 0)
	{
		ft_put_char('0');
		return (1);
	}
	else
	{
		print_hex(n, mychar);
	}
	return (hex_length(n) + sign);
}
