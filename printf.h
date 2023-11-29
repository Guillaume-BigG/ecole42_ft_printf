/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:29:44 by gbeaudoi          #+#    #+#             */
/*   Updated: 2023/11/28 20:39:26 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	int		zero;
	int		dot;
	int		dash;
	int		hastag;
	int		plus;
	int		count;
	int		width_flag;
	int		precision_flag;
	int		space;
}			t_print;

int			ft_printf(const char *str, ...);
t_print		*ft_initialize(t_print *format);
void		ft_putchar(t_print *format, char c);
void		ft_zero(t_print *format, int i);
void		ft_space(t_print *format, int i);
void		ft_flag_sign(t_print *format);
int			ft_flag_dash(t_print *format);
int			ft_flag_prec_int(t_print *format);
int			ft_check_sign(int i);
void		ft_check_zero(t_print *format, int m, int sign);
int			ft_len_digit(t_print *format, const char *str, int i);
void		ft_convert(t_print *format, const char *str, int i);
int			ft_flags(t_print *format, const char *str, int i);
void		ft_print_char(t_print *format);
int			ft_count_width(t_print *format, int k);
int			ft_count_prec(t_print *format, char *str);
void		ft_print_str(t_print *format);
int			ft_count_width_pointer(t_print *format, unsigned long p);
void		ft_pointer_convert(t_print *format, unsigned long p);
void		ft_print_pointer(t_print *format);
int			ft_get_di_len(int i);
void		ft_putnbr(t_print *format, int n);
int			ft_count_prec_id(t_print *format, int i);
int			ft_count_width_id(t_print *format, int k, int sign);
void		ft_print_intdec(t_print *format);
int			ft_get_u_len(unsigned int i);
void		ft_putnbr_u(t_print *format, unsigned int n);
int			ft_count_prec_u(t_print *format, unsigned int i);
int			ft_count_width_u(t_print *format, int k);
void		ft_print_uns_dec(t_print *format);
int			ft_get_hex_len(unsigned int i);
int			ft_count_width_hex(t_print *format, int k);
int			ft_count_prec_hex(t_print *format, int i);
void		ft_hex_convert(t_print *format, unsigned int i, int flag);
void		ft_put_hashtag(t_print *format, int flag);
void		ft_print_hex(t_print *format, int flag);
void		ft_check_str(t_print *format, char *str, int k);
void		ft_check_zero_hex(t_print *format, int flag, int m, int k);
void		ft_check_pointer(t_print *format, unsigned long p);
void		ft_check_intdec(t_print *format, int sign, int k, int m);

#endif