/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:55:19 by hmiyake           #+#    #+#             */
/*   Updated: 2018/07/31 10:38:22 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precision(const char *str, int i, va_list ap)
{
	int	num;

	num = -1;
	if (str[i] == '.')
	{
		num = 0;
		i++;
		if (str[i] == '*')
			num = va_arg(ap, int);
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - 48);
			i++;
		}
	}
	return (num);
}

int	skip_precision(const char *str, int i)
{
	while (str[i] == '.' || str[i] == '*' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	return (i);
}
