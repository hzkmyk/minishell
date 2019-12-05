/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_s_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:37:39 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 22:59:36 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	m_no_l_w_is_biggest(char *a, int *w_n_p, int count, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	a = (char *)malloc(sizeof(char) * (w_n_p[0] + 1));
	if (w_n_p[1] > count || w_n_p[1] == -1)
	{
		while (i < count)
			i = increase_together(a, s, i);
		while (i < w_n_p[0])
			a[i++] = ' ';
	}
	else
	{
		while (i < w_n_p[1])
			i = increase_together(a, s, i);
		while (i < w_n_p[0])
			a[i++] = ' ';
	}
	a[i] = '\0';
	put_and_free(a);
	return (i);
}

int	m_no_l_p_is_biggest(char *a, int *w_n_p, int count, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (w_n_p[0] > count)
	{
		a = (char *)malloc(sizeof(char) * (w_n_p[0] + 1));
		while (i < count)
			i = increase_together(a, s, i);
		while (i < w_n_p[0])
			a[i++] = ' ';
		a[i] = '\0';
		put_and_free(a);
	}
	else
		i = nothing(s, count);
	return (i);
}

int	m_no_l_c_is_biggest(char *a, int *w_n_p, int count, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (w_n_p[1] == -1)
		return (nothing(s, count));
	else if (w_n_p[0] >= w_n_p[1] && w_n_p[1] != -1)
	{
		a = malloc_a_and_put_null(a, w_n_p);
		while (i < w_n_p[1])
			i = increase_together(a, s, i);
		while (i < w_n_p[0])
			a[i++] = ' ';
	}
	else
	{
		a = (char *)malloc(sizeof(char) * (w_n_p[1] + 1));
		while (i < w_n_p[1])
			i = increase_together(a, s, i);
	}
	a[i] = '\0';
	put_and_free(a);
	return (i);
}

int	minus_n_no_l_2(va_list ap, char *s, int *w_n_p)
{
	int		count;
	char	*a;

	s = (char *)va_arg(ap, wchar_t *);
	count = count2(s);
	a = NULL;
	if (w_n_p[0] == 0 && w_n_p[1] == -1)
		return (nothing(s, count));
	else if (w_n_p[0] >= w_n_p[1] && w_n_p[0] >= count)
		return (m_no_l_w_is_biggest(a, w_n_p, count, s));
	else if (w_n_p[0] < w_n_p[1] && w_n_p[1] > count)
		return (m_no_l_p_is_biggest(a, w_n_p, count, s));
	else
		return (m_no_l_c_is_biggest(a, w_n_p, count, s));
}
