/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:17:08 by gbeaudoi          #+#    #+#             */
/*   Updated: 2023/11/28 19:41:34 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_flag_prec_int(t_print *format)
{
	if (format->precision_flag && format->zero)
		return (1);
	else if (format->precision_flag && !(format->zero))
		return (1);
	else if (!(format->precision_flag) && format->zero)
		return (0);
	else
		return (-1);
}

int	ft_check_sign(int i)
{
	if (i < 0)
		return (0);
	else
		return (1);
}

void	ft_check_zero(t_print *format, int m, int sign)
{
	if (ft_flag_prec_int(format))
	{
		ft_space(format, m);
		if (sign)
			ft_flag_sign(format);
	}
	else
	{
		if (sign)
			ft_flag_sign(format);
		ft_zero(format, m);
	}
}

void	ft_put_hashtag(t_print *format, int flag)
{
	if (format->hastag)
	{
		if (flag == 1)
			format->count += write(1, "0x", 2);
		else
			format->count += write(1, "0X", 2);
	}
}

void	ft_check_zero_hex(t_print *format, int flag, int m, int k)
{
	if (ft_flag_dash(format))
	{
		ft_space(format, m);
		ft_flag_sign(format);
		ft_put_hashtag(format, flag);
		ft_zero(format, k);
	}
	else
	{
		ft_flag_sign(format);
		ft_put_hashtag(format, flag);
		ft_zero(format, m);
		ft_zero(format, k);
	}
}
