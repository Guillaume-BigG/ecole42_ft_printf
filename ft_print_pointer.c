/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:53:34 by gbeaudoi          #+#    #+#             */
/*   Updated: 2023/11/28 19:36:41 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_count_width_pointer(t_print *format, unsigned long p)
{
	int	len;

	if (p == 0)
		len = 5;
	else
		len = 14;
	if (format->plus && format->space)
		len++;
	else if (format->plus || format->space)
		len++;
	if (format->width <= len)
		return (0);
	else
		return (format->width - len);
}

void	ft_pointer_convert(t_print *format, unsigned long p)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (p >= 16)
		ft_pointer_convert(format, p / 16);
	format->count += write(1, &hex[p % 16], 1);
}

void	ft_check_pointer(t_print *format, unsigned long p)
{
	if (p == 0)
		format->count += write(1, "(nil)", 5);
	else
	{
		format->count += write(1, "0x", 2);
		ft_pointer_convert(format, p);
	}
}

void	ft_print_pointer(t_print *format)
{
	unsigned long	p;
	int				m;

	p = va_arg(format->args, unsigned long);
	m = ft_count_width_pointer(format, p);
	if (format->dash)
	{
		ft_flag_sign(format);
		ft_check_pointer(format, p);
		ft_space(format, m);
	}
	else
	{
		ft_space(format, m);
		ft_flag_sign(format);
		ft_check_pointer(format, p);
	}
}
