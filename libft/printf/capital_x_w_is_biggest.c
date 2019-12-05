/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_capital_x_w_is_biggest.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:55:05 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/30 17:00:12 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cap_x_1_w_2_p(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;
	int	j;

	i = 0;
	if (flag_check(save_f, '#'))
	{
		while (i < (w_n_p[0] - w_n_p[1] - 2))
			i = put_space(i);
		i = capital_x_put_flag(save_f, i);
	}
	else
	{
		while (i < (w_n_p[0] - w_n_p[1]))
			i = put_space(i);
	}
	j = i;
	while (i < (w_n_p[1] - count4(num, w_n_p) + j))
		i = put_zero(i);
	capital_x_ft_putnumber(num);
	return (i);
}

int	cap_x_1_w_2_p_with_minus(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;
	int	j;

	i = 0;
	if (flag_check(save_f, '#'))
	{
		i = capital_x_put_flag(save_f, i);
		j = i;
		while (i < (w_n_p[1] - count4(num, w_n_p) + j))
			i = put_zero(i);
		capital_x_ft_putnumber(num);
		j = i;
		while (i < (w_n_p[0] - w_n_p[1] - 2 + j))
			i = put_space(i);
	}
	else
	{
		while (i < (w_n_p[1] - count4(num, w_n_p)))
			i = put_zero(i);
		capital_x_ft_putnumber(num);
		j = i;
		while (i < (w_n_p[0] - w_n_p[1] + j))
			i = put_space(i);
	}
	return (i);
}

int	cap_x_1_w_2_c(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;

	i = 0;
	if (flag_check(save_f, '#'))
	{
		while (i < (w_n_p[0] - count4(num, w_n_p) - 2))
			i = put_space(i);
		i = capital_x_put_flag(save_f, i);
	}
	else
	{
		while (i < (w_n_p[0] - count4(num, w_n_p)))
			i = put_space(i);
	}
	capital_x_ft_putnumber(num);
	return (i);
}

int	cap_x_1_w_2_c_with_minus(char *save_f, int *w_n_p, uintmax_t num)
{
	int	i;
	int	j;

	i = 0;
	if (flag_check(save_f, '#'))
	{
		i = capital_x_put_flag(save_f, i);
		capital_x_ft_putnumber(num);
		j = i;
		while (i < (w_n_p[0] - count4(num, w_n_p) - 2 + j))
			i = put_space(i);
	}
	else
	{
		capital_x_ft_putnumber(num);
		while (i < (w_n_p[0] - count4(num, w_n_p)))
			i = put_space(i);
	}
	return (i);
}
