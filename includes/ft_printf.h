/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:43:38 by ivanderw          #+#    #+#             */
/*   Updated: 2023/04/06 18:26:15 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

int		get_printchar_length(char n);

int		get_printstr_length(char *str);

int		get_printdecimal_length(int n);

int		get_printunsignedint_length(unsigned int n);

int		hex_length(unsigned int n);
void	print_hex(unsigned int n, const char mychar);
int		get_printhex_length(unsigned int n, const char mychar);

int		ft_address_length(uintptr_t n);
void	ft_printaddress(uintptr_t n);
int		get_printaddress_length(unsigned long long my_ptr);

void	ft_put_char(char c);
void	ft_put_str(char *str);
int		get_output_length(va_list args, const char mychar);
int		ft_printf(const char *inputstr, ...);

#endif
