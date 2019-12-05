/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:54:36 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 14:06:19 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width(const char *str, int i, va_list ap)
{
	int	num;

	num = 0;
	if (str[i] == '*')
		num = va_arg(ap, int);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

int	skip_width(const char *str, int i)
{
	while (str[i] == '*' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	return (i);
}
