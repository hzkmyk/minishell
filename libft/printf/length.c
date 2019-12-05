/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:56:53 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 15:29:54 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		initialize_save_l(char *save_l)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		save_l[i] = 0;
		i++;
	}
}

char		*length(const char *str, char *save_l, int i)
{
	int	h;

	h = 0;
	save_l = (char *)malloc(sizeof(char) * 2);
	initialize_save_l(save_l);
	while (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
	{
		save_l[h] = str[i];
		h++;
		i++;
	}
	return (save_l);
}

int			skip_length(const char *str, int i)
{
	while (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
		i++;
	return (i);
}

intmax_t	length_d(char *save_l, va_list ap)
{
	intmax_t num;

	if (*save_l == 'h' && *(save_l + 1) == 'h')
		num = (signed char)va_arg(ap, intmax_t);
	else if (*save_l == 'h')
		num = (short)va_arg(ap, intmax_t);
	else if (*save_l == 'l' && *(save_l + 1) == 'l')
		num = (long long)va_arg(ap, intmax_t);
	else if (*save_l == 'l')
		num = (long)va_arg(ap, intmax_t);
	else if (*save_l == 'j')
		num = va_arg(ap, intmax_t);
	else if (*save_l == 'z')
		num = (size_t)va_arg(ap, intmax_t);
	else
		num = (int)va_arg(ap, intmax_t);
	return (num);
}

uintmax_t	length_x(char *save_l, va_list ap)
{
	uintmax_t num;

	if (*save_l == 'h' && *(save_l + 1) == 'h')
		num = (unsigned char)va_arg(ap, uintmax_t);
	else if (*save_l == 'h')
		num = (unsigned short)va_arg(ap, uintmax_t);
	else if (*save_l == 'l' && *(save_l + 1) == 'l')
		num = (unsigned long long)va_arg(ap, uintmax_t);
	else if (*save_l == 'l')
		num = (unsigned long)va_arg(ap, uintmax_t);
	else if (*save_l == 'j')
		num = va_arg(ap, uintmax_t);
	else if (*save_l == 'z')
		num = (size_t)va_arg(ap, uintmax_t);
	else
		num = (unsigned int)va_arg(ap, uintmax_t);
	return (num);
}
