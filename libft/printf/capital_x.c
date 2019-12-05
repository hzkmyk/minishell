/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_capital_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:49:35 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/30 17:28:31 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	capital_x_put_flag(char *save_f, int i)
{
	if (flag_check(save_f, '#'))
	{
		ft_putchar('0');
		ft_putchar('X');
		i = i + 2;
	}
	return (i);
}

int	capital_x_c_is_biggest(char *save_f, uintmax_t num)
{
	int	i;

	i = 0;
	i = capital_x_put_flag(save_f, i);
	capital_x_ft_putnumber(num);
	return (i);
}

int	capital_x_p_is_biggest(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;
	int	j;

	i = 0;
	i = capital_x_put_flag(save_f, i);
	j = i;
	while (i < (w_n_p[1] - count4(num, w_n_p) + j))
	{
		ft_putnumber(0);
		i++;
	}
	capital_x_ft_putnumber(num);
	return (i);
}

int	specifier_capital_x(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
	uintmax_t	num;
	int			i;

	num = length_x(save_l, ap);
	if (count4(num, w_n_p) >= w_n_p[0] && count4(num, w_n_p) >= w_n_p[1])
		i = count4(num, w_n_p) + capital_x_c_is_biggest(save_f, num);
	else if (w_n_p[1] > count4(num, w_n_p) && w_n_p[1] >= w_n_p[0])
		i = count4(num, w_n_p) + capital_x_p_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[0] > count4(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] >= count4(num, w_n_p) && flag_check(save_f, '-'))
		i = count4(num, w_n_p) + cap_x_1_w_2_p_with_minus(save_f, w_n_p, num);
	else if (w_n_p[0] > count4(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] >= count4(num, w_n_p))
		i = count4(num, w_n_p) + cap_x_1_w_2_p(save_f, w_n_p, num);
	else if (w_n_p[0] > count4(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] <= count4(num, w_n_p) && flag_check(save_f, '-'))
		i = count4(num, w_n_p) + cap_x_1_w_2_c_with_minus(save_f, w_n_p, num);
	else
		i = count4(num, w_n_p) + cap_x_1_w_2_c(save_f, w_n_p, num);
	return (i);
}
