/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:45:47 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/21 22:48:28 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		make_it_home(t_minishell *shell, char *temp, int i)
{
	char	*key;
	char	*new;

	key = keyword("HOME=", 5, shell->env);
	temp = temp[0] == '~' ? temp + 1 : temp + 5;
	new = ft_strjoin(key, temp);
	ft_strdel(&(shell->list[i]));
	shell->list[i] = new;
	ft_strdel(&key);
}

void		replace_arr(t_minishell *shell, int i, char *arr)
{
	ft_strdel(&(shell->list[i]));
	shell->list[i] = arr;
}

void		handle_dollar(int i, t_minishell *shell)
{
	int		size;
	char	*key;
	char	*arr;

	size = ft_strlen(shell->list[i]);
	arr = ft_strjoin(shell->list[i] + 1, "=");
	key = keyword(arr, size, shell->env);
	ft_strdel(&arr);
	if (key)
	{
		ft_strdel(&(shell->list[i]));
		shell->list[i] = ft_strdup(key);
		ft_strdel(&key);
	}
	else
		ft_printf("%s: Undefined variable.\n", shell->list[i] + 1);
}
