/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:23:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/22 21:26:14 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_env(char *str, t_minishell *shell)
{
	t_env	*tenv;
	t_env	*first;

	if (shell->env)
	{
		first = shell->env;
		while (first->next)
			first = first->next;
		tenv = new_node(str);
		first->next = tenv;
	}
	else
		shell->env = new_node(str);
}

int		find_key(char *key, t_minishell *shell)
{
	t_env	*temp;

	temp = shell->env;
	while (temp)
	{
		if (ft_strnequ(temp->elem, key, ft_strlen(key)))
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	unset_env2(t_env *temp, char *str)
{
	t_env	*temp2;

	while (temp->next)
	{
		temp2 = temp->next;
		if (temp2 && ft_strnequ(temp2->elem, str, ft_strlen(str)))
		{
			temp->next = temp2->next;
			ft_strdel(&temp2->elem);
			ft_nodel(temp2);
			return ;
		}
		temp = temp->next;
	}
}

void	unset_env(t_minishell *shell)
{
	t_env	*temp;
	char	*str;

	temp = shell->env;
	if (!shell->list[1] || temp == NULL)
		return ;
	str = ft_strjoin(shell->list[1], "=");
	if (temp && ft_strnequ(temp->elem, str, ft_strlen(str)))
	{
		shell->env = shell->env->next;
		ft_strdel(&temp->elem);
		ft_nodel(temp);
		return ;
	}
	unset_env2(temp, str);
	ft_strdel(&str);
}

void	set_env(t_minishell *shell)
{
	char	*temp;
	char	*temp2;

	if (!shell->list[1])
	{
		print_env(shell->env);
		return ;
	}
	temp = ft_strjoin(shell->list[1], "=");
	if (shell->list[2])
		temp2 = ft_strjoin(temp, shell->list[2]);
	if (!find_key(temp, shell))
		shell->list[2] ? add_env(temp2, shell) : add_env(temp, shell);
	else
		shell->list[2] ? update_env(temp, temp2, shell) :
		update_env(temp, temp, shell);
	if (shell->list[2])
		free(temp);
}
