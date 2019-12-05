/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:56:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/04 21:45:13 by hmiyake          ###   ########.fr       */
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

void	print_env(void)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
}

void	print_echo(char *line)
{
	char	**temp;
	char	*key;
	int		i;
	int		j;
	int		space;
	int		size;
	char	*key2;

	temp = ft_strsplit(line, ' ', '\t');
	i = 1;
	space = 0;
	size = 0;
	while (temp[i])
	{
		j = 0;
		if (space)
			ft_printf(" ");
		if (temp[i][0] == '~')
		{
			key = keyword("HOME=", 5);
			ft_printf("%s", key);
			j++;
			space = 1;
			if (temp[i][1] == '/')
			{
				ft_printf("/");
				j++;
				while (temp[i][j])
				{
					ft_printf("%c", temp[i][j]);
					j++;
				}
			}
			else if (temp[i][1])
				ft_printf("no such user or named directory");
		}
		else if (temp[i][0] == '$' && temp[i][1])
		{
			size = ft_strlen(temp[i] + 1);
			key2 = ft_strdup(temp[i] + 1);
			key = keyword(key2, size);
			if (key)
			{
				ft_printf("%s", key + 1);
				space = 1;
			}
			else
				ft_printf("\n");
		}
		else
		{
			ft_printf(temp[i]);
			space = 1;
		}
		i++;
	}
	ft_printf("\n");
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
			free(line);
			write (0, "$> ", 3);
		}
	}
}
