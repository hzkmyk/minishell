/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:49:24 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/02 00:51:44 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>

int			characters(int *w_n_p, const char *str);
int			increase_and_skip(int *w_n_p, const char *str);
void		initialize_save(int *w_n_p);
int			c_to_x(va_list ap, char **save, int *w_n_p, const char *str);
int			o_to_percentage(va_list ap, char **save,
int *w_n_p, const char *str);
int			specifier(va_list ap, char **save, int *w_n_p, const char *str);
int			ft_printf(const char *str, ...);

int			specifier_capital_c(va_list ap, char *save_f, int *w_n_p);
int			specifier_capital_d(va_list ap, char *save_f, int *w_n_p);
int			specifier_capital_o(va_list ap, char *save_f, int *w_n_p);
int			specifier_capital_s(va_list ap, char *save_f, int *w_n_p);
int			specifier_capital_u(va_list ap, char *save_f, int *w_n_p);

int			cap_x_1_w_2_p(char *save_f, int *w_n_p, uintmax_t num);
int			cap_x_1_w_2_p_with_minus(char *save_f, int *w_n_p, uintmax_t num);
int			cap_x_1_w_2_c(char *save_f, int *w_n_p, uintmax_t num);
int			cap_x_1_w_2_c_with_minus(char *save_f, int *w_n_p, uintmax_t num);
int			capital_x_put_flag(char *save_f, int i);
int			capital_x_c_is_biggest(char *save_f, uintmax_t num);
int			capital_x_p_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int			specifier_capital_x(va_list ap, char *save_f,
int *w_n_p, char *save_l);

int			minus_n_l(va_list ap, wint_t w, int *w_n_p, int i);
int			minus_n_no_l(va_list ap, unsigned char c, int *w_n_p, int i);
int			no_minus_n_l(va_list ap, wint_t w, int *w_n_p, int i);
int			no_minus_n_no_l(va_list ap, unsigned char c, int *w_n_p, int i);
int			specifier_small_c(va_list ap, char *save_f,
int *w_n_p, char *save_l);

int			d_wcp_positive_with_flag(char *save_f, int *w_n_p,
intmax_t num, int i);
int			d_wcp_positive(char *save_f, int *w_n_p, intmax_t num, int i);
int			d_wcp(char *save_f, int *w_n_p, intmax_t num);
int			d_wcp_with_m_positive(char *save_f, int *w_n_p, intmax_t num);
int			d_wcp_with_m_negative(int *w_n_p, intmax_t num);
int			d_wpc_positive(char *save_f, int *w_n_p, int i);
int			d_wpc(char *save_f, int *w_n_p, intmax_t num);
int			d_wpc_with_m_positive(char *save_f, int *w_n_p, intmax_t num);
int			d_wpc_with_m_negative(int *w_n_p, intmax_t num);
int			d_wpc_with_m(char *save_f, int *w_n_p, intmax_t num);
int			c_is_biggest(char *save_f, int *w_n_p, intmax_t num);
int			p_is_biggest(char *save_f, int *w_n_p, intmax_t num);
int			d_wcp_with_m(char *save_f, int *w_n_p, intmax_t num);
int			d_wcp_negative(char *save_f, int *w_n_p, intmax_t num, int i);
int			specifier_small_d(va_list ap, char *save_f,
int *w_n_p, char *save_l);

int			o_wpc(char *save_f, int *w_n_p, uintmax_t num);
int			o_wpc_with_m(char *save_f, int *w_n_p, uintmax_t num);
int			o_wcp_with_pounds(char *save_f, int *w_n_p,
uintmax_t num, int i);
int			o_wcp(char *save_f, int *w_n_p, uintmax_t num);
int			o_wcp_with_m(char *save_f, int *w_n_p, uintmax_t num);
int			o_put_flag(char *save_f, int i, uintmax_t num);
int			o_c_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int			o_p_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int			specifier_small_o(va_list ap, char *save_f,
int *w_n_p, char *save_l);

void		p_put_flag(void);
void		p_c_is_bigger(uintmax_t num);
void		p_w_is_bigger(char *save_f, int *w_n_p, uintmax_t num);
int			specifier_small_p(va_list ap, char *save_f, int *w_n_p);

int			nothing_l(wchar_t *w, int count);
int			increase_together_l(wchar_t *a, wchar_t *w, int i);
int			fill_with_space(wchar_t *a, int i);
int			fill_with_space_2(wchar_t *a, int i);
wchar_t		*malloc_a_and_put_null_l(wchar_t *a, int *w_n_p);
int			no_m_n_l_w_is_biggest(wchar_t *w, int *w_n_p,
int count, wchar_t *a);
int			no_m_n_l_p_is_biggest(wchar_t *w, int *w_n_p,
int count, wchar_t *a);
int			no_m_n_l_c_is_biggest(wchar_t *w, int *w_n_p,
int count, wchar_t *a);
int			no_minus_n_l_2(va_list ap, wchar_t *w, int *w_n_p);
int			m_n_l_w_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a);
int			m_n_l_p_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a);
int			m_n_l_c_is_biggest(wchar_t *w, int *w_n_p, int count, wchar_t *a);
int			minus_n_l_2(va_list ap, wchar_t *w, int *w_n_p);
int			m_no_l_w_is_biggest(char *a, int *w_n_p, int count, char *s);
int			m_no_l_p_is_biggest(char *a, int *w_n_p, int count, char *s);
int			m_no_l_c_is_biggest(char *a, int *w_n_p, int count, char *s);
int			minus_n_no_l_2(va_list ap, char *s, int *w_n_p);
int			nothing(char *s, int count);
int			go_to_the_end_of_width(int i, int *w_n_p);
int			increase_together(char *a, char *s, int i);
char		*malloc_a_and_put_null(char *a, int *w_n_p);
void		put_and_free(void *a);
int			no_m_no_l_w_is_biggest(char *a, int *w_n_p, int count, char *s);
int			no_m_no_l_p_is_biggest(char *a, int *w_n_p, int count, char *s);
int			no_m_no_l_c_is_biggest(char *a, int *w_n_p, int count, char *s);
int			no_minus_n_no_l_2(va_list ap, char *s, int *w_n_p);
int			specifier_small_s(va_list ap, char *save_f,
int *w_n_p, char *save_l);

int			u_c_is_biggest(uintmax_t num);
int			u_p_is_biggest(int *w_n_p, uintmax_t num);
int			u_w_is_biggest_p_is_second(char *save_f, int *w_n_p, uintmax_t num);
int			u_w_is_biggest_c_is_second(char *save_f, int *w_n_p, uintmax_t num);
int			specifier_small_u(va_list ap, char *save_f,
int *w_n_p, char *save_l);

int			x_wpc(char *save_f, int *w_n_p, uintmax_t num);
int			x_wpc_with_m(char *save_f, int *w_n_p, uintmax_t num);
int			x_wcp_with_pound(char *save_f, int *w_n_p, uintmax_t num, int i);
int			x_wcp(char *save_f, int *w_n_p, uintmax_t num);
int			x_wcp_with_m(char *save_f, int *w_n_p, uintmax_t num);
int			x_put_flag(char *save_f, int i, uintmax_t num);
int			x_c_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int			x_p_is_biggest(char *save_f, int *w_n_p, uintmax_t num);
int			specifier_small_x(va_list ap, char *save_f,
int *w_n_p, char *save_l);

int			specifier_percentage_with_flag(char *save_f, int *w_n_p);
int			specifier_percentage(char *save_f, int *w_n_p);

int			count1(wchar_t *w);
int			count2(char *s);
int			count3(uintmax_t num, int *w_n_p);
int			count4(uintmax_t num, int *w_n_p);
int			count5(uintmax_t num, int *w_n_p);
int			count6(intmax_t num, int *w_n_p);

void		ft_putchar(char c);
wchar_t		*put_st(wchar_t *w);
char		*put_str(char *str);
int			put_space(int i);
int			put_zero(int i);
void		ft_putnumber(uintmax_t n);
void		d_ft_putnumber(intmax_t n);
void		x_ft_putnumber(uintmax_t n);
void		capital_x_ft_putnumber(uintmax_t n);
void		small_o_ft_putnumber(uintmax_t n);

void		initialize_save_f(char *save_f);
char		*flag(const char *str, char *save_f, int i);
int			put_flag(char *save_f, int i);
int			skip_flag(const char *str, int i);
int			flag_check(char *save_f, char flag);

int			width(const char *str, int i, va_list ap);
int			skip_width(const char *str, int i);

int			precision(const char *str, int i, va_list ap);
int			skip_precision(const char *str, int i);

void		initialize_save_l(char *save_l);
char		*length(const char *str, char *save_l, int i);
int			skip_length(const char *str, int i);
intmax_t	length_d(char *save_l, va_list ap);
uintmax_t	length_x(char *save_l, va_list ap);

#endif
