/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:56:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/07 16:28:59 by hmiyake          ###   ########.fr       */
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

void		save_env(t_minishell *shell)
{
	extern char	**environ;
	int			size;
	int			i;

	size = size_of_env(environ);
	shell->env = (char **)malloc(sizeof(char *) * (size + 1));
	shell->env[size] = NULL;
	i = 0;
	while (i < size)
	{
		shell->env[i] = ft_strdup(environ[i]);
		i++;
	}
}

char		*keyword(char *word, int size, t_minishell *shell)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (shell->env[i])
	{
		if (ft_strnequ(shell->env[i], word, size))
		{
			temp = ft_strdup(shell->env[i] + size);
			break;
		}
		i++;
	}
	return (temp);
}

t_minishell	*init_shell(void)
{
	t_minishell	*shell;
	char		bud[100];
	
	shell = (t_minishell *)malloc(sizeof(t_minishell));
	shell->current_path = ft_strdup(getcwd(bud, 100));
	shell->last_path = NULL;
	shell->last_path = NULL;
	save_env(shell);
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
				print_env(shell);
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
