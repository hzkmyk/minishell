/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:56:35 by hmiyake           #+#    #+#             */
/*   Updated: 2018/04/25 19:08:41 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		o;
	char	*hay;

	i = 0;
	hay = (char *)haystack;
	if (*needle == 0)
		return (hay);
	while (hay[i] != '\0')
	{
		o = 0;
		while (hay[i + o] == needle[o])
		{
			if (needle[o + 1] == '\0')
				return (hay + i);
			o++;
		}
		i++;
	}
	return (0);
}
