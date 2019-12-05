/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:42:21 by hmiyake           #+#    #+#             */
/*   Updated: 2018/04/25 18:45:00 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dstr;
	char	*sstr;

	i = 0;
	dstr = (char *)dst;
	sstr = (char *)src;
	if (sstr >= dstr)
	{
		while (i < len)
		{
			dstr[i] = sstr[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			dstr[len - 1] = sstr[len - 1];
			len--;
		}
	}
	return (dstr);
}
