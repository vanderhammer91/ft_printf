/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:19:01 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/06 18:37:57 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_put_char(str[i]);
		i++;
	}
}

int	get_output_length(va_list args, const char mychar)
{
	int	length;

	length = 0;
	if (mychar == 'c')
		length += get_printchar_length(va_arg(args, int));
	else if (mychar == 's')
		length += get_printstr_length(va_arg(args, char *));
	else if (mychar == 'd' || mychar == 'i')
		length += get_printdecimal_length(va_arg(args, int));
	else if (mychar == 'X' || mychar == 'x')
		length += get_printhex_length(va_arg(args, unsigned int), mychar);
	else if (mychar == 'u')
		length += get_printunsignedint_length(va_arg(args, unsigned int));
	else if (mychar == 'p')
		length += get_printaddress_length(va_arg(args, unsigned long long));
	else if (mychar == '%')
	{
		length++;
		ft_put_char('%');
	}
	return (length);
}

int	ft_printf(const char *inputstr, ...)
{
	int		i;
	va_list	args;
	int		output_length;

	va_start(args, inputstr);
	i = 0;
	output_length = 0;
	while (inputstr[i])
	{
		if (inputstr[i] == '%')
		{
			output_length += get_output_length(args, inputstr[(i + 1)]);
			i++;
		}
		else
			output_length += get_printchar_length(inputstr[i]);
		i++;
	}
	va_end(args);
	return (output_length);
}

/*
#ifdef _MAIN_
int	main(void)
{
	int	result = ft_printf("mresult:%c\n", '0');
	//printf("printf: %x\n", -10);
	int cresult = printf("cresult:%c\n", '0');
	printf("m:%d c:%d",result, cresult);
	return (0);
}
#endif
*/
