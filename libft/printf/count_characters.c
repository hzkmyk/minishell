/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 10:13:06 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 14:03:42 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count1(wchar_t *w)
{
	int i;

	i = 0;
	if (w)
	{
		while (w[i] != '\0')
			i++;
		return (i);
	}
	else
		return (6);
}

int	count2(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	else
		return (6);
}
