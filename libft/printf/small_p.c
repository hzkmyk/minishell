/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_small_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:45:52 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/31 18:35:38 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_put_flag(void)
{
	ft_putchar('0');
	ft_putchar('x');
}

void	p_c_is_bigger(uintmax_t num)
{
	int	i;

	i = 0;
	p_put_flag();
	x_ft_putnumber(num);
}

void	p_w_is_bigger(char *save_f, int *w_n_p, uintmax_t num)
{
	int i;

	i = 0;
	if (flag_check(save_f, '-'))
	{
		p_put_flag();
		x_ft_putnumber(num);
		while (i < (w_n_p[0] - (count4(num, w_n_p) + 2)))
			i = put_space(i);
	}
	else
	{
		while (i < (w_n_p[0] - (count4(num, w_n_p) + 2)))
			i = put_space(i);
		p_put_flag();
		x_ft_putnumber(num);
	}
}

int		specifier_small_p(va_list ap, char *save_f, int *w_n_p)
{
	uintmax_t	num;

	num = (uintmax_t)va_arg(ap, void *);
	if ((count4(num, w_n_p) + 2) >= w_n_p[0])
	{
		p_c_is_bigger(num);
		return (count4(num, w_n_p) + 2);
	}
	else
	{
		p_w_is_bigger(save_f, w_n_p, num);
		return (w_n_p[0]);
	}
}
