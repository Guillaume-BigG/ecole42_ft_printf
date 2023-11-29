/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:26:50 by gbeaudoi          #+#    #+#             */
/*   Updated: 2023/11/27 17:15:25 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_char(t_print *format)
{
	unsigned char	c;
	int				k;

	k = ft_count_width(format, 1);
	c = va_arg(format->args, int);
	if (format->dash)
	{
		ft_putchar(format, c);
		ft_space(format, k);
	}
	else
	{
		ft_space(format, k);
		ft_putchar(format, c);
	}
}
