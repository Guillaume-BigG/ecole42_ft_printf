/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_intdec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:30:27 by gbeaudoi          #+#    #+#             */
/*   Updated: 2023/11/28 20:41:27 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_get_di_len(int i)
{
	int	len;

	len = 0;
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(t_print *format, int n)
{
	unsigned int	i;

	if (n < 0)
		i = n * -1;
	else
		i = n;
	if (i >= 0 && i < 10)
		ft_putchar(format, i + 48);
	else
	{
		ft_putnbr(format, i / 10);
		ft_putnbr(format, i % 10);
	}
}

int	ft_count_prec_id(t_print *format, int i)
{
	if (format->precision > i)
		return (format->precision - i);
	else
		return (0);
}

int	ft_count_width_id(t_print *format, int k, int sign)
{
	int	len;

	len = 0;
	if (!sign)
		len ++;
	else if (format->plus || format->space)
		len++;
	if (format->width <= k + len)
		return (0);
	else
		return (format->width - k - len);
}

void	ft_print_intdec(t_print *format)
{
	int	i;
	int	sign;
	int	k;
	int	m;

	i = va_arg(format->args, int);
	sign = ft_check_sign(i);
	k = ft_count_prec_id(format, ft_get_di_len(i));
	m = ft_count_width_id(format, ft_get_di_len(i) + k, sign);
	if (format->dash)
	{
		if (sign)
			ft_flag_sign(format);
		else
			ft_putchar(format, '-');
		ft_zero(format, k);
		ft_putnbr(format, i);
		ft_space(format, m);
	}
	else
	{
		ft_check_intdec(format, sign, k, m);
		ft_putnbr(format, i);
	}
}
