/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:45:04 by gbeaudoi          #+#    #+#             */
/*   Updated: 2023/11/28 19:35:42 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(t_print *format, char c)
{
	format->count += write(1, &c, 1);
}

void	ft_zero(t_print *format, int i)
{
	int	k;

	k = -1;
	while (++k < i)
		format->count += write(1, "0", 1);
}

void	ft_space(t_print *format, int i)
{
	int	k;

	k = -1;
	while (++k < i)
		format->count += write(1, " ", 1);
}

void	ft_flag_sign(t_print *format)
{
	if (format->plus && format->space)
		format->count += write(1, "+", 1);
	else if (format->plus && !(format->space))
		format->count += write(1, "+", 1);
	else if (!(format->plus) && format->space)
		format->count += write(1, " ", 1);
}

int	ft_flag_dash(t_print *format)
{
	if (format->dash && format->zero)
		return (1);
	else if (format->dash && !(format->zero))
		return (1);
	else if (!(format->dash) && format->zero)
		return (0);
	else
		return (-1);
}
