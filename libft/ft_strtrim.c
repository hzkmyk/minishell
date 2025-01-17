/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:25:30 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/10 19:01:39 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char a, char b)
{
	char	*str;
	int		len;

	if (!s)
		return (0);
	while (*s == ' ' || *s == '\t' || *s == a || *s == b)
		s++;
	len = ft_strlen(s);
	while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\t'
				|| s[len - 1] == a || s[len - 1] == b))
		len--;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		ft_strncpy(str, s, len);
		str[len] = '\0';
	}
	return (str);
}
