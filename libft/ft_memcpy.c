/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:16:05 by hmiyake           #+#    #+#             */
/*   Updated: 2018/04/25 18:44:17 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dstr;
	char	*sstr;

	i = 0;
	dstr = (char *)dst;
	sstr = (char *)src;
	while (i < n)
	{
		dstr[i] = sstr[i];
		i++;
	}
	return (dst);
}
