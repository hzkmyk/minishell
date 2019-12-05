/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_x_w_is_biggest.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:47:03 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 15:54:30 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_wpc(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;
	int	j;

	i = 0;
	if (flag_check(save_f, '#'))
	{
		while (i < (w_n_p[0] - w_n_p[1] - 2))
			i = put_space(i);
		i = x_put_flag(save_f, i, num);
	}
	else
	{
		while (i < (w_n_p[0] - w_n_p[1]))
			i = put_space(i);
	}
	j = i;
	while (i < (w_n_p[1] - count4(num, w_n_p) + j))
		i = put_zero(i);
	x_ft_putnumber(num);
	return (i);
}

int	x_wpc_with_m(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;
	int	j;

	i = 0;
	if (flag_check(save_f, '#'))
	{
		i = x_put_flag(save_f, i, num);
		j = i;
		while (i < (w_n_p[1] - count4(num, w_n_p) + j))
			i = put_zero(i);
		x_ft_putnumber(num);
		j = i;
		while (i < (w_n_p[0] - w_n_p[1] - 2 + j))
			i = put_space(i);
	}
	else
	{
		while (i < (w_n_p[1] - count4(num, w_n_p)))
			i = put_zero(i);
		x_ft_putnumber(num);
		j = i;
		while (i < (w_n_p[0] - w_n_p[1] + j))
			i = put_space(i);
	}
	return (i);
}

int	x_wcp_with_pound(char *save_f, int *w_n_p, uintmax_t num, int i)
{
	if (flag_check(save_f, '0'))
	{
		i = x_put_flag(save_f, i, num);
		while (i < (w_n_p[0] - count4(num, w_n_p)))
			i = put_zero(i);
	}
	else
	{
		while (i < (w_n_p[0] - count4(num, w_n_p) - 2))
			i = put_space(i);
		i = x_put_flag(save_f, i, num);
	}
	return (i);
}

int	x_wcp(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;

	i = 0;
	if (flag_check(save_f, '#'))
		i = x_wcp_with_pound(save_f, w_n_p, num, i);
	else
	{
		if (flag_check(save_f, '0'))
		{
			while (i < (w_n_p[0] - count4(num, w_n_p)))
				i = put_zero(i);
		}
		else
		{
			while (i < (w_n_p[0] - count4(num, w_n_p)))
				i = put_space(i);
		}
	}
	if (num == 0 && w_n_p[1] == 0)
		return (i);
	else
	{
		x_ft_putnumber(num);
		return (i);
	}
}

int	x_wcp_with_m(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;
	int	j;

	i = 0;
	if (flag_check(save_f, '#'))
	{
		i = x_put_flag(save_f, i, num);
		x_ft_putnumber(num);
		j = i;
		while (i < (w_n_p[0] - count4(num, w_n_p) - 2 + j))
			i = put_space(i);
	}
	else
	{
		x_ft_putnumber(num);
		while (i < (w_n_p[0] - count4(num, w_n_p)))
			i = put_space(i);
	}
	return (i);
}
