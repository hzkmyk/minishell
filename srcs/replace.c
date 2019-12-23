/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:01:47 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/22 17:04:46 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			unmatched_count(char *new)
{
	ft_strdel(&new);
	return (unmatched());
}

int			do_replace(t_minishell *shell, char *temp, int i)
{
	char	*new;

	if (temp[0] == '~' || ft_strnequ(temp, "$HOME", 5))
		make_it_home(shell, temp, i);
	else if (ft_strequ(temp, "/"))
		replace_arr(shell, i, ft_strdup("/"));
	else if (temp[0] == '$' && temp[1])
		handle_dollar(i, shell);
	else if (quot_ver1(temp))
	{
		new = ft_strtrim2(temp, '\"', '\'');
		if (!same_count(new))
			return (unmatched_count(new));
		replace_arr(shell, i, new);
	}
	else if (match_q(temp))
	{
		new = trim_chars(temp, '\"', '\'');
		replace_arr(shell, i, new);
	}
	else if (quot_ver2(temp))
		return (unmatched());
	else if (!match_q(temp))
		return (unmatched());
	return (0);
}

int			replace(t_minishell *shell)
{
	int		i;
	char	*temp;

	i = 0;
	while (shell->list[i])
	{
		temp = shell->list[i];
		if (do_replace(shell, temp, i))
			return (1);
		i++;
	}
	return (0);
}
