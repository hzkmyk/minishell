/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:23:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/09 23:13:31 by hmiyake          ###   ########.fr       */
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
			printf("%s\n", str);
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

void	unset_env(char *line, t_minishell *shell)
{
	char	**input;
	t_env	*temp;
	t_env	*temp2;
	char	*str;

	input = ft_strsplit(line, ' ', '\t');
	if (!input[1])
		return ;
	temp = shell->env;
	if (temp == NULL) 
	{
		ft_printf("Env is empty\n");
		return;
	}
	str = ft_strjoin(input[1], "=");
	if (temp && ft_strnequ(temp->elem, str, ft_strlen(str)))
	{
		// temp = shell->env;
		// if (shell->env->next)
		shell->env = shell->env->next;
		// ft_printf("tempelem:%s\n", shell->env->elem);
		ft_strdel(&temp->elem);
		// temp2 = temp->next;
		free(temp);
		temp = NULL;
		// ft_printf("tempelem:%s\n", temp->elem);
		return ;
	}
	// temp = shell->env;
	while (temp->next)
	{
		temp2 = temp->next;
		if (temp2 && ft_strnequ(temp2->elem, str, ft_strlen(str)))
		{
			// if (temp2->next)
				temp->next = temp2->next;
			// else
			// 	temp2 = NULL;
			// free(temp2->elem);
			ft_printf("aaa\n");
			ft_strdel(&temp2->elem);
			free(temp2);
			temp2 = NULL;
			return;
			// ft_printf("%s\n", temp2->elem);
		}
		temp = temp->next;
	}
}

void	set_env(char *line, t_minishell *shell)
{
	char	**input;
	char	*temp;
	char	*temp2;


	input = ft_strsplit(line, ' ', '\t');
	if (!input[1])
	{
		print_env(shell->env);
		return ;
	}
	temp = ft_strjoin(input[1], "=");
	if (input[2])
		temp2 = ft_strjoin(temp, input[2]);
	if (!find_key(temp, shell))
		input[2] ? add_env(temp2, shell): add_env(temp, shell);
	else
		input[2] ? update_env(temp, temp2, shell): update_env(temp, temp, shell);
	if (input[2])
		free(temp);
	ft_free(input);
}
