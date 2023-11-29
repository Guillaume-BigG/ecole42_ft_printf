/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:21:57 by gbeaudoi          #+#    #+#             */
/*   Updated: 2023/11/28 15:14:51 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_len_digit(t_print *format, const char *str, int i)
{
	if (str[i - 1] == '.')
	{
		while (isdigit(str[i]))
		{
			format->precision = format->precision * 10 + (str[i] - 48);
			format->precision_flag = 1;
			i++;
		}
	}
	else
	{
		while (isdigit(str[i]))
		{
			format->width = format->width * 10 + (str[i] - 48);
			format->width_flag = 1;
			i++;
		}
	}
	return (i);
}

void	ft_convert(t_print *format, const char *str, int i)
{
	if (str[i] == 'c')
		ft_print_char(format);
	else if (str[i] == 's')
		ft_print_str(format);
	else if (str[i] == 'p')
		ft_print_pointer(format);
	else if (str[i] == 'i' || str[i] == 'd')
		ft_print_intdec(format);
	else if (str[i] == 'u')
		ft_print_uns_dec(format);
	else if (str[i] == 'x')
		ft_print_hex(format, 1);
	else if (str[i] == 'X')
		ft_print_hex(format, 0);
	else if (str[i] == '%')
		ft_putchar(format, '%');
	else
		return ;
}

int	ft_check_flag(t_print *format, const char *str, int i)
{
	if (str[i] == '0' || str[i] == '-' || str[i] == '#' || str[i] == ' '
		|| str[i] == '+' || str[i] == '.')
	{
		if (str[i] == '0')
			format->zero = 1;
		if (str[i] == '-')
			format->dash = 1;
		if (str[i] == '#')
			format->hastag = 1;
		if (str[i] == ' ')
			format->space = 1;
		if (str[i] == '+')
			format->plus = 1;
		if (str[i] == '.')
			format->precision_flag = 1;
		i++;
	}
	else if (ft_isdigit(str[i]))
		i = ft_len_digit(format, str, i);
	return (i);
}

int	ft_flags(t_print *format, const char *str, int i)
{
	while (str[i] != 'c' && str[i] != 's' && str[i] != 'p' && str[i] != 'd'
		&& str[i] != 'i' && str[i] != 'u' && str[i] != 'x' && str[i] != 'X'
		&& str[i] != '%')
	{
		i = ft_check_flag(format, str, i);
	}
	ft_convert(format, str, i);
	return (i);
}
