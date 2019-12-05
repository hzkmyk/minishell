/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_d_wcp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:26:32 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/31 18:19:40 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	d_wcp_positive_with_flag(char *save_f, int *w_n_p, intmax_t num, int i)
{
	if (flag_check(save_f, '0') && w_n_p[1] == -1)
	{
		i = put_flag(save_f, i);
		while (i < (w_n_p[0] - count6(num, w_n_p)))
			i = put_zero(i);
	}
	else
	{
		while (i < (w_n_p[0] - count6(num, w_n_p) - 1))
			i = put_space(i);
		put_flag(save_f, i);
	}
	return (i);
}

int	d_wcp_positive(char *save_f, int *w_n_p, intmax_t num, int i)
{
	if (flag_check(save_f, '+') || flag_check(save_f, ' '))
		i = d_wcp_positive_with_flag(save_f, w_n_p, num, i);
	else
	{
		if (flag_check(save_f, '0') && w_n_p[1] == -1)
		{
			while (i < (w_n_p[0] - count6(num, w_n_p)))
				i = put_zero(i);
		}
		else
		{
			while (i < (w_n_p[0] - count6(num, w_n_p)))
				i = put_space(i);
		}
	}
	return (i);
}

int	d_wcp(char *save_f, int *w_n_p, intmax_t num)
{
	int i;

	i = 0;
	if (num >= 0)
		i = d_wcp_positive(save_f, w_n_p, num, i);
	else if (num < 0)
	{
		i = d_wcp_negative(save_f, w_n_p, num, i);
		num = num * -1;
	}
	if (num == 0 && w_n_p[1] == 0)
		return (i);
	else
	{
		d_ft_putnumber(num);
		return (i);
	}
}

int	d_wcp_with_m_positive(char *save_f, int *w_n_p, intmax_t num)
{
	int	i;
	int	j;

	i = 0;
	if (flag_check(save_f, '+') || flag_check(save_f, ' '))
	{
		i = put_flag(save_f, i);
		d_ft_putnumber(num);
		j = i;
		while (i < (w_n_p[0] - count6(num, w_n_p) - 1 + j))
			i = put_space(i);
	}
	else
	{
		d_ft_putnumber(num);
		while (i < (w_n_p[0] - count6(num, w_n_p)))
			i = put_space(i);
	}
	return (i);
}

int	d_wcp_with_m_negative(int *w_n_p, intmax_t num)
{
	int	i;
	int	j;

	i = 0;
	ft_putchar('-');
	i++;
	num = num * -1;
	d_ft_putnumber(num);
	j = i;
	while (i < (w_n_p[0] - count6(num, w_n_p) - 1 + j))
		i = put_space(i);
	return (i);
}
