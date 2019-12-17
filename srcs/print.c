/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:20:33 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/16 20:44:02 by hmiyake          ###   ########.fr       */
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

int		handle_dollar(char *temp, t_minishell *shell)
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

void	print_echo(char **list, t_minishell *shell)
{
	int		i;
	int		space;

	i = 1;
	space = 0;
	while (list[i])
	{
		if (space)
			ft_printf(" ");
		if (list[i][0] == '$' && list[i][1])
			space = handle_dollar(list[i], shell);
		else
		{
			ft_printf(list[i]);
			space = 1;
		}
		i++;
	}
	ft_printf("\n");
}
