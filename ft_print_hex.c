/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:48 by gbeaudoi          #+#    #+#             */
/*   Updated: 2023/11/28 19:41:18 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"
#include <stdarg.h>

int	ft_get_hex_len(unsigned int i)
{
	int	len;

	len = 0;
	if (i <= 0)
		len = 1;
	while (i != 0)
	{
		i /= 16;
		len++;
	}
	return (len);
}

int	ft_count_width_hex(t_print *format, int k)
{
	int	len;

	len = 0;
	if (format->plus && format->space)
		len++;
	else if (format->plus || format->space)
		len++;
	else if (format->hastag)
		len += 2;
	if (format->width <= k + len)
		return (0);
	else
		return (format->width - k - len);
}

int	ft_count_prec_hex(t_print *format, int i)
{
	if (format->precision > i)
		return (format->precision - i);
	else
		return (0);
}

void	ft_hex_convert(t_print *format, unsigned int i, int flag)
{
	char	*low;
	char	*up;

	low = "0123456789abcdef";
	up = "0123456789ABCDEF";
	if (flag == 1)
	{
		if (i >= 16)
			ft_hex_convert(format, i / 16, flag);
		format->count += write(1, &low[i % 16], 1);
	}
	else
	{
		if (i >= 16)
			ft_hex_convert(format, i / 16, flag);
		format->count += write(1, &up[i % 16], 1);
	}
}

void	ft_print_hex(t_print *format, int flag)
{
	unsigned int	i;
	int				k;
	int				m;

	i = va_arg(format->args, unsigned int);
	k = ft_count_prec_hex(format, ft_get_hex_len(i));
	m = ft_count_width_hex(format, ft_get_hex_len(i) + k);
	if (format->dash)
	{
		ft_flag_sign(format);
		ft_put_hashtag(format, flag);
		ft_zero(format, k);
		ft_hex_convert(format, i, flag);
		ft_space(format, m);
	}
	else
	{
		ft_check_zero_hex(format, flag, m, k);
		ft_hex_convert(format, i, flag);
	}
}
