/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:52:46 by hmiyake           #+#    #+#             */
/*   Updated: 2018/08/01 15:29:01 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_save_f(char *save_f)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		save_f[i] = 0;
		i++;
	}
}

char	*flag(const char *str, char *save_f, int i)
{
	int	h;

	h = 0;
	save_f = (char *)malloc(sizeof(char) * 5);
	initialize_save_f(save_f);
	while (str[i] == '#' || str[i] == '0' || str[i] == '+'
			|| str[i] == '-' || str[i] == ' ')
	{
		if (!flag_check(save_f, str[i]))
		{
			save_f[h] = str[i];
			h++;
		}
		i++;
	}
	return (save_f);
}

int		put_flag(char *save_f, int i)
{
	if (flag_check(save_f, '+'))
	{
		ft_putchar('+');
		i++;
	}
	else if (flag_check(save_f, ' '))
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int		skip_flag(const char *str, int i)
{
	while (str[i] == '#' || str[i] == '0' || str[i] == '+'
			|| str[i] == '-' || str[i] == ' ')
		i++;
	return (i);
}

int		flag_check(char *save_f, char flag)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (save_f[i] == flag)
			return (1);
		i++;
	}
	return (0);
}
