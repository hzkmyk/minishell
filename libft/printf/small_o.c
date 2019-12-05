/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 09:36:32 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 14:20:29 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	o_put_flag(char *save_f, int i, uintmax_t num)
{
	if (flag_check(save_f, '#') && num != 0)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

int	o_c_is_biggest(char *save_f, int *w_n_p, uintmax_t num)
{
	int i;

	i = 0;
	if (num == 0 && w_n_p[1] == 0 && flag_check(save_f, '#'))
	{
		ft_putchar('0');
		i++;
		return (i);
	}
	else if (num == 0 && w_n_p[1] == 0)
		return (i);
	else
	{
		i = o_put_flag(save_f, i, num);
		small_o_ft_putnumber(num);
		return (i);
	}
}

int	o_p_is_biggest(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;
	int	j;

	i = 0;
	if (flag_check(save_f, '#'))
	{
		i = o_put_flag(save_f, i, num);
		j = i;
		while (i < (w_n_p[1] - count5(num, w_n_p) + j))
			i = put_zero(i);
	}
	else
	{
		while (i < (w_n_p[1] - count5(num, w_n_p)))
			i = put_zero(i);
	}
	small_o_ft_putnumber(num);
	return (i);
}

int	specifier_small_o(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
	uintmax_t	num;
	int			i;

	num = length_x(save_l, ap);
	if (count5(num, w_n_p) >= w_n_p[0] && count5(num, w_n_p) >= w_n_p[1])
		i = count5(num, w_n_p) + o_c_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[1] > count5(num, w_n_p) && w_n_p[1] >= w_n_p[0])
		i = count5(num, w_n_p) + o_p_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1]
	&& w_n_p[1] > count5(num, w_n_p) && flag_check(save_f, '-'))
		i = count5(num, w_n_p)
		+ o_wpc_with_m(save_f, w_n_p, num);
	else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1]
	&& w_n_p[1] > count5(num, w_n_p))
		i = count5(num, w_n_p) + o_wpc(save_f, w_n_p, num);
	else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1]
	&& w_n_p[1] < count5(num, w_n_p) && flag_check(save_f, '-'))
		i = count5(num, w_n_p)
		+ o_wcp_with_m(save_f, w_n_p, num);
	else
		i = count5(num, w_n_p) + o_wcp(save_f, w_n_p, num);
	return (i);
}
