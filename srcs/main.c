/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:56:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/17 01:02:56 by hmiyake          ###   ########.fr       */
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
	save_env(shell->env);
	return (shell);
}

void		handler(int num)
{
	(void)num;
	ft_printf("\033[4G  \n$> ");
}

char		**replace(char **list, t_minishell *shell)
{
	int		i;
	char	*temp;
	char	*key;
	char	*new;
	
	i = 0;
	key = keyword("HOME=", 5, shell->env);
	while(list[i])
	{
		temp = list[i];
		if (temp[0] == '~' || ft_strnequ(temp, "$HOME", 5))
		{
			temp = temp[0] == '~' ? temp + 1: temp + 5;
			new = ft_strjoin(key, temp);
			ft_strdel(&(list[i]));
			list[i] = ft_strdup(new);
		}
		if (ft_strequ(temp, "/"))
		{
			ft_strdel(&(list[i]));
			list[i] = ft_strdup("/");
		}
		i++;
	}
	return (list);
}

int			main(void)
{
	char		*line;
	t_minishell	*shell;
	char		**list;

	signal(SIGINT, handler);
	shell = init_shell();
	while (1)
	{
		write (0, "$> ", 3);
		while (get_next_line(0, &line))
		{
			list = ft_strsplit(line, ' ', '\t');
			list = replace(list, shell);
			if (ft_strnequ(line, "setenv ", 7))
				set_env(line, shell);
			else if (ft_strnequ(line, "unsetenv ", 9))
				unset_env(line, shell);
			else if (ft_strequ(line, "env") || ft_strnequ(line, "setenv", 6))
				print_env(shell->env);
			else if (ft_strequ(line, "exit"))
				exit(EXIT_SUCCESS);
			else if (ft_strnequ(line, "echo ", 5))
				print_echo(list, shell);
			else if (ft_strnequ(line, "cd ", 3))
				cd(list, shell);
			else
				real_func(list, shell);
			/*
			else 
				callRealFunction()
			----------------------------------
			callRealFunction(cmd *char)

			loop over bins
			{
				open bin 
				loop over files in bin
				[
					compare to cmd
					if yes
						fork & exec
				]
			}
			if cmd was not found in any bin
				return "no comand found" + cmd


			*/
			ft_strdel(&line);
			ft_free(list);
			write (0, "$> ", 3);
		}
	}
}
