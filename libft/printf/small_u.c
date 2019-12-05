/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:11:59 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 13:15:24 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_c_is_biggest(uintmax_t num)
{
	ft_putnumber(num);
	return (0);
}

int	u_p_is_biggest(int *w_n_p, uintmax_t num)
{
	int	i;

	i = 0;
	while (i < (w_n_p[1] - count3(num, w_n_p)))
		i = put_zero(i);
	ft_putnumber(num);
	return (i);
}

int	u_w_is_biggest_p_is_second(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;
	int	j;

	i = 0;
	if (flag_check(save_f, '-'))
	{
		while (i < (w_n_p[1] - count3(num, w_n_p)))
			i = put_zero(i);
		ft_putnumber(num);
		j = i;
		while (i < (w_n_p[0] - w_n_p[1] + j))
			i = put_space(i);
	}
	else
	{
		while (i < (w_n_p[0] - w_n_p[1]))
			i = put_space(i);
		j = i;
		while (i < (w_n_p[1] - count3(num, w_n_p) + j))
			i = put_zero(i);
		ft_putnumber(num);
	}
	return (i);
}

int	u_w_is_biggest_c_is_second(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;

	i = 0;
	if (flag_check(save_f, '-'))
	{
		ft_putnumber(num);
		while (i < (w_n_p[0] - count3(num, w_n_p)))
			i = put_space(i);
	}
	else
	{
		if (flag_check(save_f, '0'))
		{
			while (i < (w_n_p[0] - count3(num, w_n_p)))
				i = put_zero(i);
		}
		else
		{
			while (i < (w_n_p[0] - count3(num, w_n_p)))
				i = put_space(i);
		}
		ft_putnumber(num);
	}
	return (i);
}

int	specifier_small_u(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
	uintmax_t	num;
	int			i;

	num = length_x(save_l, ap);
	if (count3(num, w_n_p) >= w_n_p[0] && count3(num, w_n_p) >= w_n_p[1])
		i = count3(num, w_n_p) + u_c_is_biggest(num);
	else if (w_n_p[1] > count3(num, w_n_p) && w_n_p[1] >= w_n_p[0])
		i = count3(num, w_n_p) + u_p_is_biggest(w_n_p, num);
	else if (w_n_p[0] > count3(num, w_n_p) && w_n_p[0] > w_n_p[1]
	&& w_n_p[1] >= count3(num, w_n_p))
		i = count3(num, w_n_p) + u_w_is_biggest_p_is_second(save_f, w_n_p, num);
	else
		i = count3(num, w_n_p) + u_w_is_biggest_c_is_second(save_f, w_n_p, num);
	return (i);
}
