/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printdecimal_length.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:36:24 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/06 17:18:26 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	get_printdecimal_length(int n)
{
	int	length;

	length = 1;
	if (n == INT_MIN)
	{
		ft_put_str("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_put_char('-');
		n = -n;
		length += get_printdecimal_length(n);
	}
	else if (n == 0)
		ft_put_char('0');
	else if (n >= 10)
	{
		length += get_printdecimal_length(n / 10);
		ft_put_char(n % 10 + '0');
	}
	else
		ft_put_char(n % 10 + '0');
	return (length);
}
