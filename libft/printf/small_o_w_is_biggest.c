/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_o_w_is_biggest.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 10:34:08 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 15:54:22 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	o_wpc(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;
	int	j;

	i = 0;
	if (flag_check(save_f, '#'))
	{
		while (i < (w_n_p[0] - w_n_p[1]))
			i = put_space(i);
		i = o_put_flag(save_f, i, num);
		j = i;
		while (i < (w_n_p[1] - count5(num, w_n_p)) - 1 + j)
			i = put_zero(i);
	}
	else
	{
		while (i < (w_n_p[0] - w_n_p[1]))
			i = put_space(i);
		j = i;
		while (i < (w_n_p[1] - count5(num, w_n_p) + j))
			i = put_zero(i);
	}
	small_o_ft_putnumber(num);
	return (i);
}

int	o_wpc_with_m(char *save_f, int *w_n_p, uintmax_t num)
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
		small_o_ft_putnumber(num);
		j = i;
		while (i < (w_n_p[0] - w_n_p[1] + j))
			i = put_space(i);
	}
	else
	{
		while (i < (w_n_p[1] - count5(num, w_n_p)))
			i = put_zero(i);
		small_o_ft_putnumber(num);
		j = i;
		while (i < (w_n_p[0] - w_n_p[1] + j))
			i = put_space(i);
	}
	return (i);
}

int	o_wcp_with_pounds(char *save_f, int *w_n_p, uintmax_t num, int i)
{
	if (flag_check(save_f, '0'))
	{
		i = o_put_flag(save_f, i, num);
		while (i < (w_n_p[0] - count5(num, w_n_p)))
			i = put_zero(i);
	}
	else
	{
		while (i < (w_n_p[0] - count5(num, w_n_p) - 1))
			i = put_space(i);
		i = o_put_flag(save_f, i, num);
	}
	return (i);
}

int	o_wcp(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;

	i = 0;
	if (flag_check(save_f, '#'))
		i = o_wcp_with_pounds(save_f, w_n_p, num, i);
	else
	{
		if (flag_check(save_f, '0'))
		{
			while (i < (w_n_p[0] - count5(num, w_n_p)))
				i = put_zero(i);
		}
		else
		{
			while (i < (w_n_p[0] - count5(num, w_n_p)))
				i = put_space(i);
		}
	}
	if (num == 0 && w_n_p[1] == 0)
		return (i);
	else
	{
		small_o_ft_putnumber(num);
		return (i);
	}
}

int	o_wcp_with_m(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;

	i = 0;
	if (flag_check(save_f, '#'))
	{
		i = o_put_flag(save_f, i, num);
		small_o_ft_putnumber(num);
		while (i < (w_n_p[0] - count5(num, w_n_p)))
			i = put_space(i);
	}
	else
	{
		small_o_ft_putnumber(num);
		while (i < (w_n_p[0] - count5(num, w_n_p)))
			i = put_space(i);
	}
	return (i);
}
