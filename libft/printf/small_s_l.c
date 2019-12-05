/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_s_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 21:06:27 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 15:05:18 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	no_m_n_l_w_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	a = malloc_a_and_put_null_l(a, w_n_p);
	if (w_n_p[1] > count || w_n_p[1] == -1)
	{
		go_to_the_end_of_width(i, w_n_p);
		while (i >= (w_n_p[0] - count))
			a[i--] = w[count - j++];
		while (i > -1)
			i = fill_with_space(a, i);
	}
	else
	{
		go_to_the_end_of_width(i, w_n_p);
		while (i >= (w_n_p[0] - w_n_p[1]))
			a[i--] = w[w_n_p[1] - j++];
		while (i > -1)
			i = fill_with_space(a, i);
	}
	put_and_free(a);
	return (i);
}

int	no_m_n_l_p_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (w_n_p[0] > count)
	{
		a = malloc_a_and_put_null_l(a, w_n_p);
		i = go_to_the_end_of_width(i, w_n_p);
		while (i >= (w_n_p[0] - count))
			a[i--] = w[count - j++];
		while (i > -1)
			i = fill_with_space(a, i);
		put_and_free(a);
	}
	else
		return (nothing_l(w, count));
	return (i);
}

int	no_m_n_l_c_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (w_n_p[1] == -1)
		return (nothing_l(w, count));
	else if (w_n_p[0] >= w_n_p[1])
	{
		a = malloc_a_and_put_null_l(a, w_n_p);
		i = go_to_the_end_of_width(i, w_n_p);
		while (i >= (w_n_p[0] - w_n_p[1]))
			a[i--] = w[w_n_p[1] - j++];
		while (i > -1)
			i = fill_with_space(a, i);
	}
	else
	{
		a = (wchar_t *)malloc(sizeof(wchar_t) * (w_n_p[1] + 1));
		while (i < w_n_p[1])
			i = increase_together_l(a, w, i);
		a[w_n_p[1]] = '\0';
	}
	put_and_free(a);
	return (i);
}

int	no_minus_n_l_2(va_list ap, wchar_t *w, int *w_n_p)
{
	int		count;
	wchar_t	*a;

	w = va_arg(ap, wchar_t *);
	count = count1(w);
	a = NULL;
	if (w_n_p[0] == 0 && w_n_p[1] == -1)
		return (nothing_l(w, count));
	else if (w_n_p[0] >= w_n_p[1] && w_n_p[0] >= count)
		return (no_m_n_l_w_is_biggest(w, w_n_p, count, a));
	else if (w_n_p[0] < w_n_p[1] && w_n_p[1] > count)
		return (no_m_n_l_p_is_biggest(w, w_n_p, count, a));
	else
		return (no_m_n_l_c_is_biggest(w, w_n_p, count, a));
}
