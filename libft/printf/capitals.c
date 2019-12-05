/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capitals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:39:54 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/02 00:51:41 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_capital_c(va_list ap, char *save_f, int *w_n_p)
{
	wint_t	w;
	int		i;

	w = 0;
	i = 0;
	if (flag_check(save_f, '-'))
		i = minus_n_l(ap, w, w_n_p, i);
	else
		i = no_minus_n_l(ap, w, w_n_p, i);
	return (i);
}

int	specifier_capital_d(va_list ap, char *save_f, int *w_n_p)
{
	intmax_t	num;
	int			i;

	num = (long)va_arg(ap, intmax_t);
	if (count6(num, w_n_p) >= w_n_p[0] && count6(num, w_n_p) >= w_n_p[1])
		i = count6(num, w_n_p) + c_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[1] > count6(num, w_n_p) && w_n_p[1] >= w_n_p[0])
		i = count6(num, w_n_p) + p_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] >= count6(num, w_n_p) && flag_check(save_f, '-'))
		i = count6(num, w_n_p)
			+ d_wpc_with_m(save_f, w_n_p, num);
	else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] >= count6(num, w_n_p))
		i = count6(num, w_n_p) + d_wpc(save_f, w_n_p, num);
	else if (w_n_p[0] > count6(num, w_n_p) && w_n_p[0] > w_n_p[1] &&
			w_n_p[1] <= count6(num, w_n_p) && flag_check(save_f, '-'))
		i = count6(num, w_n_p)
			+ d_wcp_with_m(save_f, w_n_p, num);
	else
		i = count6(num, w_n_p) + d_wcp(save_f, w_n_p, num);
	return (i);
}

int	specifier_capital_o(va_list ap, char *save_f, int *w_n_p)
{
	uintmax_t	num;
	int			i;

	num = (unsigned long)va_arg(ap, uintmax_t);
	if (count5(num, w_n_p) >= w_n_p[0] && count5(num, w_n_p) >= w_n_p[1])
		i = count5(num, w_n_p) + o_c_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[1] > count5(num, w_n_p) && w_n_p[1] >= w_n_p[0])
		i = count5(num, w_n_p) + o_p_is_biggest(save_f, w_n_p, num);
	else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] >= count5(num, w_n_p) && flag_check(save_f, '-'))
		i = count5(num, w_n_p)
			+ o_wpc_with_m(save_f, w_n_p, num);
	else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] >= count5(num, w_n_p))
		i = count5(num, w_n_p) + o_wpc(save_f, w_n_p, num);
	else if (w_n_p[0] > count5(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] <= count5(num, w_n_p) && flag_check(save_f, '-'))
		i = count5(num, w_n_p) + o_wcp_with_m(save_f, w_n_p, num);
	else
		i = count5(num, w_n_p) + o_wcp(save_f, w_n_p, num);
	return (i);
}

int	specifier_capital_s(va_list ap, char *save_f, int *w_n_p)
{
	wchar_t	*w;
	int		i;

	w = NULL;
	if (flag_check(save_f, '-'))
		i = minus_n_l_2(ap, w, w_n_p);
	else
		i = no_minus_n_l_2(ap, w, w_n_p);
	return (i);
}

int	specifier_capital_u(va_list ap, char *save_f, int *w_n_p)
{
	uintmax_t	num;
	int			i;

	num = (unsigned long)va_arg(ap, intmax_t);
	if (count3(num, w_n_p) >= w_n_p[0] && count3(num, w_n_p) >= w_n_p[1])
		i = count3(num, w_n_p) + u_c_is_biggest(num);
	else if (w_n_p[1] > count3(num, w_n_p) && w_n_p[1] >= w_n_p[0])
		i = count3(num, w_n_p) + u_p_is_biggest(w_n_p, num);
	else if (w_n_p[0] > count3(num, w_n_p) && w_n_p[0] > w_n_p[1]
			&& w_n_p[1] >= count3(num, w_n_p))
		i = count3(num, w_n_p) + u_w_is_biggest_p_is_second(save_f, w_n_p, num);
	else
		i = count3(num, w_n_p) + u_w_is_biggest_c_is_second(save_f, w_n_p, num);
	return (i);
}
