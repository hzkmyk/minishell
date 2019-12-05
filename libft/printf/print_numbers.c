/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:16:46 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 15:13:09 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnumber(uintmax_t n)
{
	if (n >= 10)
	{
		ft_putnumber(n / 10);
		ft_putnumber(n % 10);
	}
	else
		ft_putchar(n + 48);
}

void	d_ft_putnumber(intmax_t n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnumber(-n);
	}
	else if (n >= 10)
	{
		ft_putnumber(n / 10);
		ft_putnumber(n % 10);
	}
	else
		ft_putchar(n + 48);
}

void	x_ft_putnumber(uintmax_t n)
{
	if (n >= 16)
	{
		x_ft_putnumber(n / 16);
		x_ft_putnumber(n % 16);
	}
	else
	{
		if (n == 10)
			ft_putchar('a');
		else if (n == 11)
			ft_putchar('b');
		else if (n == 12)
			ft_putchar('c');
		else if (n == 13)
			ft_putchar('d');
		else if (n == 14)
			ft_putchar('e');
		else if (n == 15)
			ft_putchar('f');
		else
			ft_putchar(n + 48);
	}
}

void	capital_x_ft_putnumber(uintmax_t n)
{
	if (n >= 16)
	{
		capital_x_ft_putnumber(n / 16);
		capital_x_ft_putnumber(n % 16);
	}
	else
	{
		if (n == 10)
			ft_putchar('A');
		else if (n == 11)
			ft_putchar('B');
		else if (n == 12)
			ft_putchar('C');
		else if (n == 13)
			ft_putchar('D');
		else if (n == 14)
			ft_putchar('E');
		else if (n == 15)
			ft_putchar('F');
		else
			ft_putchar(n + 48);
	}
}

void	small_o_ft_putnumber(uintmax_t n)
{
	if (n >= 8)
	{
		small_o_ft_putnumber(n / 8);
		small_o_ft_putnumber(n % 8);
	}
	else
		ft_putchar(n + 48);
}
