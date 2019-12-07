/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:56:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/05 20:21:33 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		size_of_env(char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
		i++;
	return (i);
}

void	save_env(void)
{
	extern char	**environ;
	int			size;
	int			i;

	size = size_of_env(environ);
	env = (char **)malloc(sizeof(char *) * (size + 1));
	env[size] = NULL;
	i = 0;
	while (i < size)
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
}

char	*keyword(char *word, int size)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (env[i])
	{
		if (ft_strnequ(env[i], word, size))
		{
			temp = ft_strdup(env[i] + size);
			break;
		}
		i++;
	}
	return (temp);
}

int		main(void)
{
	char	*line;

	save_env();
	while (1)
	{
		write (0, "$> ", 3);
		while (get_next_line(0, &line))
		{
			if (ft_strequ(line, "env"))
				print_env();
			else if (ft_strequ(line, "exit"))
				exit(EXIT_SUCCESS);
			else if (ft_strnequ(line, "echo", 4))
				print_echo(line);
			else if (ft_strnequ(line, "cd", 2))
				cd(line);
			free(line);
			write (0, "$> ", 3);
		}
	}
}
