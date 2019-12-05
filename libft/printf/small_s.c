/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:28:45 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 19:25:36 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		no_m_no_l_w_is_biggest(char *a, int *w_n_p, int count, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	a = malloc_a_and_put_null(a, w_n_p);
	if (w_n_p[1] > count || w_n_p[1] == -1)
	{
		i = go_to_the_end_of_width(i, w_n_p);
		while (i >= (w_n_p[0] - count))
			a[i--] = s[count - j++];
	}
	else
	{
		i = go_to_the_end_of_width(i, w_n_p);
		while (i >= (w_n_p[0] - w_n_p[1]))
			a[i--] = s[w_n_p[1] - j++];
	}
	while (i > -1)
		a[i--] = ' ';
	put_and_free(a);
	return (count2(a));
}

int		no_m_no_l_p_is_biggest(char *a, int *w_n_p, int count, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (w_n_p[0] > count)
	{
		a = malloc_a_and_put_null(a, w_n_p);
		i = go_to_the_end_of_width(i, w_n_p);
		while (i >= (w_n_p[0] - count))
			a[i--] = s[count - j++];
		while (i > -1)
			a[i--] = ' ';
		put_and_free(a);
	}
	else
		i = nothing(s, count);
	return (i);
}

int		no_m_no_l_c_is_biggest(char *a, int *w_n_p, int count, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (w_n_p[1] == -1)
		return (nothing(s, count));
	else if (w_n_p[0] > w_n_p[1])
	{
		a = malloc_a_and_put_null(a, w_n_p);
		i = go_to_the_end_of_width(i, w_n_p);
		while (i >= (w_n_p[0] - w_n_p[1]))
			a[i--] = s[w_n_p[1] - j++];
		while (i > -1)
			a[i--] = ' ';
	}
	else
	{
		a = (char *)malloc(sizeof(char) * (w_n_p[1] + 1));
		while (i < w_n_p[1])
			i = increase_together(a, s, i);
		a[i] = '\0';
	}
	put_and_free(a);
	return (i);
}

int		no_minus_n_no_l_2(va_list ap, char *s, int *w_n_p)
{
	int		count;
	char	*a;

	s = (char *)va_arg(ap, wchar_t *);
	count = count2(s);
	a = NULL;
	if (w_n_p[0] == 0 && w_n_p[1] == -1)
		return (nothing(s, count));
	else if (w_n_p[0] >= w_n_p[1] && w_n_p[0] >= count)
		return (no_m_no_l_w_is_biggest(a, w_n_p, count, s));
	else if (w_n_p[0] < w_n_p[1] && w_n_p[1] > count)
		return (no_m_no_l_p_is_biggest(a, w_n_p, count, s));
	else
		return (no_m_no_l_c_is_biggest(a, w_n_p, count, s));
}

int		specifier_small_s(va_list ap, char *save_f, int *w_n_p, char *save_l)
{
	wchar_t	*w;
	char	*s;
	int		i;

	w = NULL;
	s = NULL;
	i = 0;
	if (flag_check(save_f, '-'))
	{
		if (save_l[0] == 'l' && save_l[1] == '\0')
			i = minus_n_l_2(ap, w, w_n_p);
		else
			i = minus_n_no_l_2(ap, s, w_n_p);
	}
	else
	{
		if (save_l[0] == 'l' && save_l[1] == '\0')
			i = no_minus_n_l_2(ap, w, w_n_p);
		else
			i = no_minus_n_no_l_2(ap, s, w_n_p);
	}
	return (i);
}
