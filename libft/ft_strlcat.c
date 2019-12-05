/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:30:36 by hmiyake           #+#    #+#             */
/*   Updated: 2018/04/25 18:45:36 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_i;
	size_t	s_i;

	d_i = 0;
	s_i = 0;
	while (dst[d_i] != '\0' && (d_i < dstsize))
		d_i += 1;
	if (d_i < dstsize)
	{
		while ((src[s_i] != '\0') && ((s_i + d_i) < (dstsize - 1)))
		{
			dst[d_i + s_i] = src[s_i];
			s_i += 1;
		}
		dst[d_i + s_i] = '\0';
	}
	return (d_i + ft_strlen(src));
}
