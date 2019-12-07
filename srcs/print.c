/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:20:33 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/05 19:06:33 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_env(void)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
}

int		expan_one(int i, char **temp)
{
	int		j;
	char	*key;

	j = 0;
	key = keyword("HOME=", 5);
	ft_printf("%s", key);
	j++;
	if (temp[i][1] == '/')
	{
		ft_printf("/");
		j++;
		while (temp[i][j])
		{
			ft_printf("%c", temp[i][j]);
			j++;
		}
	}
	else if (temp[i][1])
		ft_printf("no such user or named directory");
	return (1);
}

int		expan_two(char *temp)
{
	int		size;
	char	*key;
	
	size = ft_strlen(temp + 1);
	temp = ft_strdup(temp + 1);
	key = keyword(temp, size);
	if (key)
	{
		ft_printf("%s", key + 1);
		return (1);
	}
	else
		ft_printf("\n");
	return (0);
}

void	print_echo(char *line)
{
	char	**temp;
	int		i;
	int		space;

	temp = ft_strsplit(line, ' ', '\t');
	i = 1;
	space = 0;
	while (temp[i])
	{
		if (space)
			ft_printf(" ");
		if (temp[i][0] == '~')
			space = expan_one(i, temp);
		else if (temp[i][0] == '$' && temp[i][1])
			space = expan_two(temp[i]);
		else
		{
			ft_printf(temp[i]);
			space = 1;
		}
		i++;
	}
	ft_printf("\n");
}
