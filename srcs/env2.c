/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:41:11 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/21 22:44:04 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		update_env(char *key, char *str, t_minishell *shell)
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

int			size_of_env(char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
		i++;
	return (i);
}

t_env		*new_node(char *str)
{
	t_env *temp;

	temp = (t_env *)malloc(sizeof(t_env));
	temp->elem = str;
	temp->next = NULL;
	return (temp);
}

void		save_env(t_env *env)
{
	extern char	**environ;
	int			size;
	int			i;
	t_env		*temp;

	env->elem = ft_strdup(environ[0]);
	size = size_of_env(environ);
	i = 1;
	while (i < size)
	{
		temp = new_node(ft_strdup(environ[i]));
		env->next = temp;
		env = env->next;
		i++;
	}
}
