/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:56:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/22 00:06:31 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*keyword(char *word, int size, t_env *env)
{
	char	*temp;

	temp = NULL;
	while (env)
	{
		if (ft_strnequ(env->elem, word, size))
		{
			temp = ft_strdup(env->elem + size);
			break ;
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
		if (arr[i] == '\'')
			sing++;
		if (sing == 2)
			sing = 0;
		if (arr[i] == '\"')
			doub++;
		if (doub == 2)
			doub = 0;
		if (sing && doub)
			return (0);
		i++;
	}
	if (sing == 1 || doub == 1)
		return (0);
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
	return (0);
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
	ft_printf("Unmatched \'.\n");
	return (1);
}

int			do_replace(t_minishell *shell, char *temp, int i)
{
	char	*new;

	if (temp[0] == '~' || ft_strnequ(temp, "$HOME", 5))
		make_it_home(shell, temp, i);
	else if (ft_strequ(temp, "/"))
		replace_arr(shell, i, ft_strdup("/"));
	else if (temp[0] == '$' && temp[1])
		handle_dollar(i, shell);
	else if (quot_ver1(temp))
	{
		new = ft_strtrim2(temp, '\"', '\'');
		if (!same_count(new))
		{
			ft_strdel(&new);
			return (unmatched());
		}
		replace_arr(shell, i, new);
	}
	else if (match_q(temp))
	{
		new = trim_chars(temp, '\"', '\'');
		replace_arr(shell, i, new);
	}
	else if (quot_ver2(temp))
		return (unmatched());
	else if (!match_q(temp))
		return (unmatched());
	return (0);
}

int			replace(t_minishell *shell)
{
	int		i;
	char	*temp;

	i = 0;
	while (shell->list[i])
	{
		temp = shell->list[i];
		if (do_replace(shell, temp, i))
			return (1);
		i++;
	}
	return (0);
}

void		do_command(char *line, t_minishell *shell)
{
	if (ft_strequ(shell->list[0], "setenv"))
		set_env(shell);
	else if (ft_strequ(shell->list[0], "unsetenv"))
		unset_env(shell);
	else if (ft_strequ(line, "env"))
		print_env(shell->env);
	else if (ft_strequ(line, "exit"))
		exit(EXIT_SUCCESS);
	else if (ft_strequ(shell->list[0], "echo"))
		print_echo(shell->list);
	else if (ft_strequ(shell->list[0], "cd"))
		cd(shell->list, shell);
	else
		real_func(shell);
}

int			main(void)
{
	char		*line;
	t_minishell	*shell;

	signal(SIGINT, handler);
	shell = init_shell();
	while (1)
	{
		write(0, "$> ", 3);
		while (get_next_line(0, &line))
		{
			shell->list = ft_strsplit2(line, ' ', '\t');
			if (!replace(shell))
				do_command(line, shell);
			ft_strdel(&line);
			ft_free(shell->list);
			write(0, "$> ", 3);
		}
	}
}
