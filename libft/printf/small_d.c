/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:21:20 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/31 18:20:58 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_is_biggest(char *save_f, int *w_n_p, intmax_t num)
{
	int	i;

	i = 0;
	if (num >= 0)
		i = put_flag(save_f, i);
	else
		i++;
	if (num == 0 && w_n_p[1] == 0)
		return (i);
	else
	{
		d_ft_putnumber(num);
		return (i);
	}
}

int	p_is_biggest(char *save_f, int *w_n_p, intmax_t num)
{
	int	i;
	int	j;

	i = 0;
	if (num >= 0)
	{
		i = put_flag(save_f, i);
		j = i;
		while (i < (w_n_p[1] - count6(num, w_n_p) + j))
			i = put_zero(i);
	}
	else if (num < 0)
	{
		ft_putchar('-');
		i++;
		while (i < (w_n_p[1] - count6(num, w_n_p) + 1))
			i = put_zero(i);
		num = num * -1;
	}
	d_ft_putnumber(num);
	return (i);
}

int	d_wcp_with_m(char *save_f, int *w_n_p, intmax_t num)
{
	if (num >= 0)
		return (d_wcp_with_m_positive(save_f, w_n_p, num));
	else
		return (d_wcp_with_m_negative(w_n_p, num));
}

int	d_wcp_negative(char *save_f, int *w_n_p, intmax_t num, int i)
{
	if (flag_check(save_f, '0') && w_n_p[1] == -1)
	{
		ft_putchar('-');
		i++;
		while (i < (w_n_p[0] - count6(num, w_n_p)))
			i = put_zero(i);
	}
	else
	{
		while (i < (w_n_p[0] - count6(num, w_n_p) - 1))
			i = put_space(i);
		ft_putchar('-');
		i++;
	}
	return (i);
}

int	specifier_small_d(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
	intmax_t	num;
	int			i;

	num = length_d(save_l, ap);
	if (count6(num, w_n_p) >= w_n_p[0] && count6(num, w_n_p) >= w_n_p[1])
		i = count6(num, w_n_p) + c_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[1] > count6(num, w_n_p) && w_n_p[1] >= w_n_p[0])
		i = count6(num, w_n_p) + p_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] > count6(num, w_n_p) && flag_check(save_f, '-'))
		i = count6(num, w_n_p)
			+ d_wpc_with_m(save_f, w_n_p, num);
	else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] > count6(num, w_n_p))
		i = count6(num, w_n_p) + d_wpc(save_f, w_n_p, num);
	else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] < count6(num, w_n_p) && flag_check(save_f, '-'))
		i = count6(num, w_n_p)
			+ d_wcp_with_m(save_f, w_n_p, num);
	else
		i = count6(num, w_n_p) + d_wcp(save_f, w_n_p, num);
	return (i);
}
