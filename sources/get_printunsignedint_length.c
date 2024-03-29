/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printunsignedint_length.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:24:49 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/06 15:59:55 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	get_printunsignedint_length(unsigned int n)
{
	int		print_length;	

	print_length = 0;
	if (n >= 10)
		print_length += get_printunsignedint_length(n / 10);
	print_length += get_printchar_length(n % 10 + '0');
	return (print_length);
}
