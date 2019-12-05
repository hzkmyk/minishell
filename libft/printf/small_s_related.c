/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_s_related.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:39:21 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 18:54:09 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nothing(char *s, int count)
{
	if (s)
		put_str(s);
	else
		put_str("(null)");
	return (count);
}

int		go_to_the_end_of_width(int i, int *w_n_p)
{
	while (i < w_n_p[0])
		i++;
	i--;
	return (i);
}

int		increase_together(char *a, char *s, int i)
{
	a[i] = s[i];
	i++;
	return (i);
}

char	*malloc_a_and_put_null(char *a, int *w_n_p)
{
	a = (char *)malloc(sizeof(char) * (w_n_p[0] + 1));
	a[w_n_p[0]] = '\0';
	return (a);
}

void	put_and_free(void *a)
{
	put_str(a);
	free(a);
}
