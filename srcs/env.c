/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:23:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/10 20:16:55 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	update_env(char *key, char *str, t_minishell *shell)
{
	t_env	*temp;

	temp = shell->env;
	while (temp)
	{
		if (ft_strnequ(temp->elem, key, ft_strlen(key)))
		{
			free(temp->elem);
			temp->elem = ft_strdup(str);
			return ;
		}
		temp = temp->next;
	}
}

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

char	*trim_and_join(char *input)
{
	char	*temp;
	char	*str;

	temp = ft_strtrim(input, '\"', '\'');
	str = ft_strjoin(temp, "=");
	free(temp);
	return (str);
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
			return;
		}
		temp = temp->next;
	}
}

void	unset_env(char *line, t_minishell *shell)
{
	char	**input;
	t_env	*temp; 
	char	*str;

	input = ft_strsplit(line, ' ', '\t');
	temp = shell->env;
	if (!input[1] || temp == NULL)
		return ;
	str = trim_and_join(input[1]);
	if (temp && ft_strnequ(temp->elem, str, ft_strlen(str)))
	{
		shell->env = shell->env->next;
		ft_strdel(&temp->elem);
		ft_nodel(temp);
		return ;
	}
	unset_env2(temp, str);
}

void	set_env(char *line, t_minishell *shell)
{
	char	**input;
	char	*temp;
	char	*temp2;
	char	*trim;

	input = ft_strsplit(line, ' ', '\t');
	if (!input[1])
	{
		print_env(shell->env);
		return ;
	}
	temp = trim_and_join(input[1]);
	if (input[2])
	{
		trim = ft_strtrim(input[2], '\"', '\'');
		temp2 = ft_strjoin(temp, trim);
		free(trim);
	}
	if (!find_key(temp, shell))
		input[2] ? add_env(temp2, shell): add_env(temp, shell);
	else
		input[2] ? update_env(temp, temp2, shell): update_env(temp, temp, shell);
	if (input[2])
		free(temp);
	ft_free(input);
}
