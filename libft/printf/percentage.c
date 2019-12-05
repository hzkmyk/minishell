/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_percentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 18:46:15 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/31 10:32:34 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_percentage_with_flag(char *save_f, int *w_n_p)
{
	int	i;

	i = 0;
	if (flag_check(save_f, '-'))
	{
		ft_putchar('%');
		while (i < w_n_p[0] - 1)
			i = put_space(i);
	}
	else if (flag_check(save_f, '0'))
	{
		while (i < w_n_p[0] - 1)
			i = put_zero(i);
		ft_putchar('%');
	}
	else
	{
		while (i < w_n_p[0] - 1)
			i = put_space(i);
		ft_putchar('%');
	}
	return (i + 1);
}

int	specifier_percentage(char *save_f, int *w_n_p)
{
	if (w_n_p[0] == 0)
	{
		ft_putchar('%');
		return (1);
	}
	else
		return (specifier_percentage_with_flag(save_f, w_n_p));
}
