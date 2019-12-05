/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:45:31 by hmiyake           #+#    #+#             */
/*   Updated: 2018/04/25 19:09:03 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dstr;
	unsigned char	*sstr;

	i = 0;
	dstr = (unsigned char *)dst;
	sstr = (unsigned char *)src;
	while (i < n)
	{
		dstr[i] = sstr[i];
		if ((unsigned char)c == sstr[i])
			return (dst + i + 1);
		i++;
	}
	return (0);
}
