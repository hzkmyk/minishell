/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:20:33 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/08 00:29:27 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_env(t_env *env)
{
	while (env)
	{
		ft_printf("%s\n", env->elem);
		env = env->next;
	}
}

int		expan_one(int i, char **temp, t_minishell *shell)
{
	int		j;
	char	*key;

	j = 0;
	key = keyword("HOME=", 5, shell->env);
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

int		expan_two(char *temp, t_minishell *shell)
{
	int		size;
	char	*key;
	
	size = ft_strlen(temp + 1);
	temp = ft_strdup(temp + 1);
	key = keyword(temp, size, shell->env);
	if (key)
	{
		ft_printf("%s", key + 1);
		return (1);
	}
	else
		ft_printf("\n");
	return (0);
}

void	print_echo(char *line, t_minishell *shell)
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
			space = expan_one(i, temp, shell);
		else if (temp[i][0] == '$' && temp[i][1])
			space = expan_two(temp[i], shell);
		else
		{
			ft_printf(temp[i]);
			space = 1;
		}
		i++;
	}
	ft_printf("\n");
}
