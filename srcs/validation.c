/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:58:53 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/22 17:00:03 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			match_q(char *arr)
{
	int	i;
	int	sing;
	int	doub;

	i = 0;
	sing = 0;
	doub = 0;
	while (arr[i])
	{
		if (arr[i] == '\'')
			sing++;
		if (sing == 2)
			sing = 0;
		if (arr[i] == '\"')
			doub++;
		if (doub == 2)
			doub = 0;
		if (sing && doub)
			return (0);
		i++;
	}
	if (sing == 1 || doub == 1)
		return (0);
	return (1);
}

int			same_count(char *arr)
{
	int	i;
	int	sing;
	int	doub;

	i = 0;
	sing = 0;
	doub = 0;
	while (arr[i])
	{
		if (arr[i] == '\'')
			sing++;
		if (sing == 2)
			sing = 0;
		if (arr[i] == '\"')
			doub++;
		if (doub == 2)
			doub = 0;
		i++;
	}
	if (sing || doub)
		return (0);
	return (1);
}

int			fir_las_same_char(char *arr, char c)
{
	if (arr[0] == c && arr[ft_strlen(arr) - 1] == c)
		return (1);
	return (0);
}

int			quot_ver1(char *arr)
{
	if (match_q(arr))
		return (0);
	if (fir_las_same_char(arr, '\'') || fir_las_same_char(arr, '\"'))
		return (1);
	return (0);
}

int			quot_ver2(char *arr)
{
	if ((arr[0] == '\"' && arr[ft_strlen(arr) - 1] != '\"') ||
		(arr[0] == '\'' && arr[ft_strlen(arr) - 1] != '\'') ||
		(arr[0] != '\"' && arr[ft_strlen(arr) - 1] == '\"') ||
		(arr[0] != '\"' && arr[ft_strlen(arr) - 1] == '\''))
		return (1);
	return (0);
}
