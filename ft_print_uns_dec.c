/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:45:12 by gbeaudoi          #+#    #+#             */
/*   Updated: 2023/11/28 19:51:37 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_get_u_len(unsigned int i)
{
	unsigned int	len;

	len = 0;
	if (i <= 0)
		len = 1;
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_u(t_print *format, unsigned int n)
{
	unsigned int	i;

	i = n;
	if (i >= 0 && i < 10)
		ft_putchar(format, i + 48);
	else
	{
		ft_putnbr(format, i / 10);
		ft_putnbr(format, i % 10);
	}
}

int	ft_count_prec_u(t_print *format, unsigned int i)
{
	if ((unsigned int)format->precision > i)
		return (format->precision - i);
	else
		return (0);
}

int	ft_count_width_u(t_print *format, int k)
{
	int	len;

	len = 0;
	if (format->plus && format->space)
		len++;
	else if (format->plus || format->space)
		len++;
	if (format->width <= k + len)
		return (0);
	else
		return (format->width - k - len);
}

void	ft_print_uns_dec(t_print *format)
{
	unsigned int	i;
	int				sign;
	int				k;
	int				m;

	i = va_arg(format->args, unsigned int);
	sign = ft_check_sign(i);
	k = ft_count_prec_u(format, ft_get_u_len(i));
	m = ft_count_width_u(format, ft_get_u_len(i) + k);
	if (format->dash)
	{
		ft_flag_sign(format);
		ft_zero(format, k);
		ft_putnbr_u(format, i);
		ft_space(format, m);
	}
	else
	{
		ft_check_zero(format, m, sign);
		ft_zero(format, k);
		ft_putnbr_u(format, i);
	}
}
