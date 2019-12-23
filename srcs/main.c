/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:56:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/22 17:02:11 by hmiyake          ###   ########.fr       */
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
