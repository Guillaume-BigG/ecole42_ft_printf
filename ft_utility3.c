/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:47:44 by gbeaudoi          #+#    #+#             */
/*   Updated: 2023/11/28 20:58:42 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_check_intdec(t_print *format, int sign, int k, int m)
{
	if (sign)
	{
		ft_flag_sign(format);
		if (format->precision_flag)
			ft_space(format, m);
		else
			ft_zero(format, m);
	}
	if (!sign)
	{
		ft_putchar(format, '-');
		if (format->precision_flag)
			ft_space(format, m);
		else
			ft_zero(format, m);
	}
	ft_zero(format, k);
}
