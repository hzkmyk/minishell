/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:10:28 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 15:38:53 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	minus_n_l(va_list ap, wint_t w, int *w_n_p, int i)
{
	w = va_arg(ap, wint_t);
	ft_putchar(w);
	if (w_n_p[0] == 0)
		return (1);
	else
	{
		i++;
		while (i < (w_n_p[0]))
			i = put_space(i);
	}
	return (i);
}

int	minus_n_no_l(va_list ap, unsigned char c, int *w_n_p, int i)
{
	c = (unsigned char)va_arg(ap, int);
	ft_putchar(c);
	if (w_n_p[0] == 0)
		return (1);
	else
	{
		i++;
		while (i < (w_n_p[0]))
			i = put_space(i);
	}
	return (i);
}

int	no_minus_n_l(va_list ap, wint_t w, int *w_n_p, int i)
{
	w = va_arg(ap, wint_t);
	if (w_n_p[0] == 0)
	{
		ft_putchar(w);
		return (1);
	}
	else
	{
		while (i < (w_n_p[0] - 1))
			i = put_space(i);
		ft_putchar(w);
	}
	return (i);
}

int	no_minus_n_no_l(va_list ap, unsigned char c, int *w_n_p, int i)
{
	c = (unsigned char)va_arg(ap, int);
	if (w_n_p[0] == 0)
	{
		ft_putchar(c);
		return (1);
	}
	else
	{
		while (i < (w_n_p[0] - 1))
			i = put_space(i);
		ft_putchar(c);
		i++;
	}
	return (i);
}

int	specifier_small_c(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
	wint_t			w;
	unsigned char	c;
	int				i;

	i = 0;
	w = 0;
	c = '\0';
	if (flag_check(save_f, '-'))
	{
		if (save_l[0] == 'l' && save_l[1] == '\0')
			i = minus_n_l(ap, w, w_n_p, i);
		else
			i = minus_n_no_l(ap, c, w_n_p, i);
	}
	else
	{
		if (save_l[0] == 'l' && save_l[1] == '\0')
			i = no_minus_n_l(ap, w, w_n_p, i);
		else
			i = no_minus_n_no_l(ap, c, w_n_p, i);
	}
	return (i);
}
