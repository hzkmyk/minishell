/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_s_m_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:16:24 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 22:59:04 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	m_n_l_w_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	a = (wchar_t *)malloc(sizeof(wchar_t) * (w_n_p[0] + 1));
	if (w_n_p[1] > count || w_n_p[1] == -1)
	{
		while (i < count)
			i = increase_together_l(a, w, i);
		while (i < w_n_p[0])
			i = fill_with_space_2(a, i);
	}
	else
	{
		while (i < w_n_p[1])
			i = increase_together_l(a, w, i);
		while (i < w_n_p[0])
			i = fill_with_space_2(a, i);
	}
	a[i] = '\0';
	put_and_free(a);
	return (i);
}

int	m_n_l_p_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (w_n_p[0] > count)
	{
		a = (wchar_t *)malloc(sizeof(wchar_t) * (w_n_p[0] + 1));
		while (i < count)
			i = increase_together_l(a, w, i);
		while (i < w_n_p[0])
			i = fill_with_space_2(a, i);
		a[i] = '\0';
		put_and_free(a);
	}
	else
		return (nothing_l(w, count));
	return (i);
}

int	m_n_l_c_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (w_n_p[1] == -1)
		return (nothing_l(w, count));
	else if (w_n_p[0] > w_n_p[1])
	{
		a = (wchar_t *)malloc(sizeof(wchar_t) * (w_n_p[0] + 1));
		while (i < w_n_p[1])
			i = increase_together_l(a, w, i);
		while (i < w_n_p[0])
			i = fill_with_space_2(a, i);
		a[w_n_p[0]] = '\0';
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

int	minus_n_l_2(va_list ap, wchar_t *w, int *w_n_p)
{
	int		count;
	wchar_t	*a;

	w = va_arg(ap, wchar_t *);
	count = count1(w);
	a = NULL;
	if (w_n_p[0] == 0 && w_n_p[1] == -1)
		return (nothing_l(w, count));
	else if (w_n_p[0] >= w_n_p[1] && w_n_p[0] >= count)
		return (m_n_l_w_is_biggest(w, w_n_p, count, a));
	else if (w_n_p[0] < w_n_p[1] && w_n_p[1] > count)
		return (m_n_l_p_is_biggest(w, w_n_p, count, a));
	else
		return (m_n_l_c_is_biggest(w, w_n_p, count, a));
}
