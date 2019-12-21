/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:56:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/21 00:41:14 by hmiyake          ###   ########.fr       */
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
	shell->list = NULL;
	save_env(shell->env);
	return (shell);
}

void		handler(int num)
{
	(void)num;
	ft_printf("\033[4G  \n$> ");
}

void		handle_dollar(int i, t_minishell *shell)
{
	int		size;
	char	*key;
	char	*arr;
	
	size = ft_strlen(shell->list[i]);
	arr = ft_strjoin(shell->list[i] + 1, "=");
	key = keyword(arr, size, shell->env);
	ft_strdel(&arr);
	if (key)
	{
		ft_strdel(&(shell->list[i]));
		shell->list[i] = ft_strdup(key);
		ft_strdel(&key);
	}
	else
		ft_printf("%s: Undefined variable.\n", shell->list[i] + 1);
}

int			match_q(char *arr)
{
	int	i;
	int	sing;
	int	doub;

	i = 0;
	sing = 0;
	doub = 0;
	while (arr[i])
	{
		// if ((arr[0] != '\'' && arr[0] != '\"') || (arr[ft_strlen(arr) - 1] != '\'' && arr[ft_strlen(arr) - 1] != '\"'))
		// 	return (0);
		if (arr[i] == '\'')
			sing++;
		if (sing == 2)
			sing = 0;
		if(arr[i] == '\"')
			doub++;
		if(doub == 2)
			doub = 0;
		if (sing && doub)
			return (0);
		i++;
	}
	return (1);
}

int			same_count(char *arr)
{
	int	i;
	int	sing;
	int	doub;

	i = 0;
	sing = 0;
	doub = 0;
	while (arr[i])
	{
		if (arr[i] == '\'')
			sing++;
		if (sing == 2)
			sing = 0;
		if (arr[i] == '\"')
			doub++;
		if (doub == 2)
			doub = 0;
		i++;
	}
	if (sing || doub)
		return (0);
	return (1);
}

int			fir_las_same_char(char *arr, char c)
{
	if (arr[0] == c && arr[ft_strlen(arr) - 1] == c)
		return (1);
	return(0);
}

int			quot_ver1(char *arr)
{
	if (match_q(arr))
		return (0);
	if (fir_las_same_char(arr, '\'') || fir_las_same_char(arr, '\"'))
		return (1);
	return (0);
}

int			quot_ver2(char *arr)
{
	if ((arr[0] == '\"' && arr[ft_strlen(arr) - 1] != '\"') ||
		(arr[0] == '\'' && arr[ft_strlen(arr) - 1] != '\'') ||
		(arr[0] != '\"' && arr[ft_strlen(arr) - 1] == '\"') ||
		(arr[0] != '\"' && arr[ft_strlen(arr) - 1] == '\''))
		return (1);
	return (0);
}

int			unmatched(void)
{
	ft_printf("Unmatched \".\n");
	return (1);
}

void		replace_arr(t_minishell *shell, int i, char *arr)
{
	ft_strdel(&(shell->list[i]));
	shell->list[i] = arr;
}

int			replace(t_minishell *shell)
{
	int		i;
	char	*temp;
	char	*key;
	char	*new;

	i = 0;
	while(shell->list[i])
	{
		temp = shell->list[i];
		if (temp[0] == '~' || ft_strnequ(temp, "$HOME", 5))
		{
			key = keyword("HOME=", 5, shell->env);
			temp = temp[0] == '~' ? temp + 1: temp + 5;
			new = ft_strjoin(key, temp);
			ft_strdel(&(shell->list[i]));
			shell->list[i] = new;
			ft_strdel(&key);
		}
		else if (ft_strequ(temp, "/"))
			replace_arr(shell, i, ft_strdup("/"));
		else if (temp[0] == '$' && temp[1])
			handle_dollar(i, shell);
		else if (quot_ver1(temp))
		{
			new = ft_strtrim2(temp, '\"', '\'');
			if (!same_count(new))
				return (unmatched());
			replace_arr(shell, i, new);
		}
		else if (match_q(temp))
		{
			new = trim_chars(temp, '\"', '\'');
			replace_arr(shell, i, new);
		}
		else if (quot_ver2(temp))
			return (unmatched());
		i++;
	}
	return (0);
}

int			main(void)
{
	char		*line;
	t_minishell	*shell;

	signal(SIGINT, handler);
	shell = init_shell();
	while (1)
	{
		write (0, "$> ", 3);
		while (get_next_line(0, &line))
		{
			shell->list = ft_strsplit2(line, ' ', '\t');
			if (replace(shell))
			{
				write (0, "$> ", 3);
				ft_strdel(&line);
				ft_free(shell->list);
				continue;
			}
			if (ft_strnequ(line, "setenv ", 7))
				set_env(line, shell);
			else if (ft_strnequ(line, "unsetenv ", 9))
				unset_env(line, shell);
			else if (ft_strequ(line, "env") || ft_strnequ(line, "setenv", 6))
				print_env(shell->env);
			else if (ft_strequ(line, "exit"))
				exit(EXIT_SUCCESS);
			else if (ft_strnequ(line, "echo ", 5))
				print_echo(shell->list);
			else if (ft_strnequ(line, "cd ", 3))
				cd(shell->list, shell);
			else
				real_func(shell);
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
			ft_free(shell->list);
			write (0, "$> ", 3);
		}
	}
}
