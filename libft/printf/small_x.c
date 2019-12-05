/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:50:09 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 15:17:46 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_put_flag(char *save_f, int i, uintmax_t num)
{
	if (flag_check(save_f, '#') && num != 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		i = i + 2;
	}
	return (i);
}

int	x_c_is_biggest(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;

	i = 0;
	i = x_put_flag(save_f, i, num);
	if (num == 0 && w_n_p[1] == 0)
		return (i);
	else
	{
		x_ft_putnumber(num);
		return (i);
	}
}

int	x_p_is_biggest(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;
	int	j;

	i = 0;
	i = x_put_flag(save_f, i, num);
	j = i;
	while (i < (w_n_p[1] - count4(num, w_n_p) + j))
		put_zero(i);
	x_ft_putnumber(num);
	return (i);
}

int	specifier_small_x(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
	uintmax_t	num;
	int			i;

	num = length_x(save_l, ap);
	if (count4(num, w_n_p) >= w_n_p[0] && count4(num, w_n_p) >= w_n_p[1])
		i = count4(num, w_n_p) + x_c_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[1] > count4(num, w_n_p) && w_n_p[1] >= w_n_p[0])
		i = count4(num, w_n_p) + x_p_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[0] > count4(num, w_n_p) && w_n_p[0] > w_n_p[1]
	&& w_n_p[1] > count4(num, w_n_p) && flag_check(save_f, '-'))
		i = count4(num, w_n_p)
		+ x_wpc_with_m(save_f, w_n_p, num);
	else if (w_n_p[0] > count4(num, w_n_p) && w_n_p[0] > w_n_p[1]
	&& w_n_p[1] > count4(num, w_n_p))
		i = count4(num, w_n_p)
		+ x_wpc(save_f, w_n_p, num);
	else if (w_n_p[0] > count4(num, w_n_p) && w_n_p[0] > w_n_p[1]
	&& w_n_p[1] < count4(num, w_n_p) && flag_check(save_f, '-'))
		i = count4(num, w_n_p)
		+ x_wcp_with_m(save_f, w_n_p, num);
	else
		i = count4(num, w_n_p) + x_wcp(save_f, w_n_p, num);
	return (i);
}
