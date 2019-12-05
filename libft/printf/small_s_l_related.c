/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_s_l_related.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:41:11 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 22:58:23 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nothing_l(wchar_t *w, int count)
{
	if (w)
		put_st(w);
	else
		put_str("(null)");
	return (count);
}

int		increase_together_l(wchar_t *a, wchar_t *w, int i)
{
	a[i] = w[i];
	i++;
	return (i);
}

int		fill_with_space(wchar_t *a, int i)
{
	a[i] = ' ';
	i--;
	return (i);
}

int		fill_with_space_2(wchar_t *a, int i)
{
	a[i] = ' ';
	i++;
	return (i);
}

wchar_t	*malloc_a_and_put_null_l(wchar_t *a, int *w_n_p)
{
	a = (wchar_t *)malloc(sizeof(wchar_t) * (w_n_p[0] + 1));
	a[w_n_p[0]] = '\0';
	return (a);
}
