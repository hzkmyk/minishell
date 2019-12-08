/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:56:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/08 00:26:42 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			size_of_env(char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
		i++;
	return (i);
}


t_env *newNode(char *str)
{
	t_env *tmp;

	tmp = malloc(sizeof(t_env));
	tmp->next = NULL;
	tmp->elem = ft_strdup(str);

	return tmp;
}

void		save_env(t_env *env)
{
	extern char	**environ;
	int			size;
	int			i;
	t_env		*temp;


	env->elem = ft_strdup(environ[0]);
	size = size_of_env(environ);
	// env->elem = ft_strdup(environ[0]);
	// env = env->next;
	i = 1;
	while (i < size)
	{
		temp = newNode(environ[i]);
		// temp = (t_env *)malloc(sizeof(t_env));
		// temp->next = NULL;

		// env->elem = ft_strdup(environ[i]);
		env->next = temp;
		env = env->next;
		i++;
	}
}

char		*keyword(char *word, int size, t_env *env)
{
	char	*temp;

	temp = NULL;
	while (env)
	{
		if (ft_strnequ(env->elem, word, size))
		{
			temp = ft_strdup(env->elem + size);
			break;
		}
		env = env->next;
	}
	return (temp);
}

t_minishell	*init_shell(void)
{
	t_minishell	*shell;
	char		bud[100];
	
	shell = (t_minishell *)malloc(sizeof(t_minishell));
	shell->env = (t_env *)malloc(sizeof(t_env));
	shell->current_path = ft_strdup(getcwd(bud, 100));
	shell->pre_path = NULL;
	shell->pre_pre_path = NULL;
	save_env(shell->env);
	return (shell);
}

int			main(void)
{
	char		*line;
	t_minishell	*shell;

	shell = init_shell();
	while (1)
	{
		write (0, "$> ", 3);
		while (get_next_line(0, &line))
		{
			if (ft_strequ(line, "env"))
				print_env(shell->env);
			else if (ft_strnequ(line, "setenv", 6))
				set_env(line, shell);
			else if (ft_strequ(line, "exit"))
				exit(EXIT_SUCCESS);
			else if (ft_strnequ(line, "echo", 4))
				print_echo(line, shell);
			else if (ft_strnequ(line, "cd", 2))
				cd(line, shell);
			free(line);
			write (0, "$> ", 3);
		}
	}
}
