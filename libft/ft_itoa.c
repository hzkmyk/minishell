/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:17:06 by hmiyake           #+#    #+#             */
/*   Updated: 2019/09/02 20:21:19 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getindex(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		neg;

	len = getindex(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	neg = 1;
	if (n < 0)
		neg = -1;
	if (num)
	{
		num[len] = '\0';
		if (n < 0)
			num[0] = '-';
		if (n == 0)
			num[0] = '0';
		while (n != 0)
		{
			num[len - 1] = ((n % 10) * neg + '0');
			n = n / 10;
			len--;
		}
		return (num);
	}
	return (0);
}
