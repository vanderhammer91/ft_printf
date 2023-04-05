/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:19:01 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/05 18:26:20 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"


void	ft_put_char(char c)
{
	write(1, &c, 1);
}

static int	get_printchar_length(int n)
{
	ft_put_char(n);
	return (1);
}

void	ft_put_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_put_char(str[i]);
		i++;
	}
}

static int	get_printstr_length(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		ft_put_str("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_put_char(str[i]);
		i++;
	}
	return (i);
}

static int	get_printdecimal_length(int n)
{
	int length;

	length = 0;
	if (n == INT_MIN)
	{
		ft_put_str("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		length++;
		ft_put_char('-');
		n = -n;
		length += get_printdecimal_length(n);
	}
	else if (n == 0)
	{
		ft_put_char('0');
		length++;
	}
	else if (n >= 10)
	{
		length += get_printdecimal_length(n / 10);
		ft_put_char(n % 10 + '0');
		length++;
	}
	else
	{
		ft_put_char(n % 10 + '0');
		length++;
	}
	return (length);
}

static int hex_length(int n)
{
	int length;

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

static int get_printhex_length(unsigned int n, const char mychar)
{
	int sign;

	sign = 0;
	if (n == 0)
	{
		ft_put_char('0');
		return (1);
	}
	else if (n < 0)
	{	
		ft_put_char('-');
		n = -n;
		print_hex(n, mychar);
		sign = 1;
	}
	else
	{
		print_hex(n, mychar);
	}
	return (hex_length(n) + sign);
}

static int	get_printunsignedint_length(unsigned int n)
{
	int		print_length;	

	print_length = 0;
	if (n >= 10)
		print_length += get_printunsignedint_length(n / 10);
	print_length += get_printchar_length(n % 10 + '0');
	return (print_length);
}

static int ft_address_length(uintptr_t n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		length ++;
		n = n / 16;
	}
	return (length);
}

void	ft_printaddress(uintptr_t n)
{
	if (n >= 16)
	{
		ft_printaddress(n / 16);
		ft_printaddress(n % 16);
	}
	else if (n < 10)
		ft_put_char(n + '0');
	else if (n >= 10 && n < 16)
		ft_put_char(n - 10 + 'a');
}

static int	get_printaddress_length(unsigned long long my_ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (my_ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_printaddress(my_ptr);
		print_length += ft_address_length(my_ptr);
	}
	return (print_length);
}

static int	get_printpercent_length()
{
	ft_put_char('%');
	return (1);
}

static int	get_output_length(va_list args, const char mychar)
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
		length += get_printpercent_length();
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
	while(inputstr[i])
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
int	main(void)
{
	int	result = 3;
//	int *my_pt = &result;
	result = ft_printf("%%\n");
	printf("result: %d \n", result);
	return (0);
}
*/
