/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 22:17:58 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/02 00:50:11 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_to_x(va_list ap, char **save, int *w_n_p, const char *str)
{
	if (str[w_n_p[3]] == 'c')
		w_n_p[2] += specifier_small_c(ap, save[0], w_n_p, save[1]);
	else if (str[w_n_p[3]] == 'C')
		w_n_p[2] += specifier_capital_c(ap, save[0], w_n_p);
	else if (str[w_n_p[3]] == 's')
		w_n_p[2] += specifier_small_s(ap, save[0], w_n_p, save[1]);
	else if (str[w_n_p[3]] == 'S')
		w_n_p[2] += specifier_capital_s(ap, save[0], w_n_p);
	else if (str[w_n_p[3]] == 'd')
		w_n_p[2] += specifier_small_d(ap, save[0], w_n_p, save[1]);
	else if (str[w_n_p[3]] == 'D')
		w_n_p[2] += specifier_capital_d(ap, save[0], w_n_p);
	else if (str[w_n_p[3]] == 'x')
		w_n_p[2] += specifier_small_x(ap, save[0], w_n_p, save[1]);
	else if (str[w_n_p[3]] == 'X')
		w_n_p[2] += specifier_capital_x(ap, save[0], w_n_p, save[1]);
	return (w_n_p[2]);
}

int	o_to_percentage(va_list ap, char **save, int *w_n_p, const char *str)
{
	if (str[w_n_p[3]] == 'o')
		w_n_p[2] += specifier_small_o(ap, save[0], w_n_p, save[1]);
	else if (str[w_n_p[3]] == 'O')
		w_n_p[2] += specifier_capital_o(ap, save[0], w_n_p);
	else if (str[w_n_p[3]] == 'u')
		w_n_p[2] += specifier_small_u(ap, save[0], w_n_p, save[1]);
	else if (str[w_n_p[3]] == 'U')
		w_n_p[2] += specifier_capital_u(ap, save[0], w_n_p);
	else if (str[w_n_p[3]] == 'i')
		w_n_p[2] += specifier_small_d(ap, save[0], w_n_p, save[1]);
	else if (str[w_n_p[3]] == 'p')
		w_n_p[2] += specifier_small_p(ap, save[0], w_n_p);
	else if (str[w_n_p[3]] == '%')
		w_n_p[2] += specifier_percentage(save[0], w_n_p);
	return (w_n_p[2]);
}

int	specifier(va_list ap, char **save, int *w_n_p, const char *str)
{
	if (str[w_n_p[3]] == 'c' || str[w_n_p[3]] == 'C'
	|| str[w_n_p[3]] == 's' || str[w_n_p[3]] == 'S'
	|| str[w_n_p[3]] == 'd' || str[w_n_p[3]] == 'D'
	|| str[w_n_p[3]] == 'x' || str[w_n_p[3]] == 'X')
		w_n_p[2] = c_to_x(ap, save, w_n_p, str);
	else
		w_n_p[2] = o_to_percentage(ap, save, w_n_p, str);
	return (w_n_p[2]);
}

int	percentage(va_list ap, char **save, int *w_n_p, const char *str)
{
	w_n_p[3]++;
	save[0] = flag(str, save[0], (w_n_p[3]));
	w_n_p[3] = skip_flag(str, w_n_p[3]);
	w_n_p[0] = width(str, w_n_p[3], ap);
	w_n_p[3] = skip_width(str, w_n_p[3]);
	w_n_p[1] = precision(str, w_n_p[3], ap);
	w_n_p[3] = skip_precision(str, w_n_p[3]);
	save[1] = length(str, save[1], w_n_p[3]);
	w_n_p[3] = skip_length(str, w_n_p[3]);
	w_n_p[2] = specifier(ap, save, w_n_p, str);
	free(save[0]);
	free(save[1]);
	return (w_n_p[2]);
}

int	ft_printf(const char *str, ...)
{
	int		w_n_p[4];
	va_list	ap;
	char	*save[2];

	w_n_p[2] = 0;
	w_n_p[3] = 0;
	va_start(ap, str);
	while (str[w_n_p[3]] != '\0')
	{
		if (str[w_n_p[3]] != '%')
		{
			ft_putchar(str[w_n_p[3]]);
			w_n_p[2]++;
		}
		if (str[w_n_p[3]] == '%')
			percentage(ap, save, w_n_p, str);
		w_n_p[3]++;
	}
	va_end(ap);
	return (w_n_p[2]);
}
