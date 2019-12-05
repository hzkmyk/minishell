/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 03:55:57 by hmiyake           #+#    #+#             */
/*   Updated: 2018/04/25 19:03:09 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	o;
	char	*hay;

	i = 0;
	hay = (char *)haystack;
	if (*needle == 0)
		return (hay);
	while ((hay[i] != '\0') && (i < len))
	{
		o = 0;
		while ((hay[i + o] == needle[o]) && ((i + o) < len))
		{
			if (needle[o + 1] == '\0')
				return (hay + i);
			o++;
		}
		i++;
	}
	return (0);
}
