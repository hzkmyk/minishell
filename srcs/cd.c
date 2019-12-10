/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:02:12 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/08 19:10:06 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	move(char *path)
{
	if (chdir(path) == -1)
		ft_printf("cd: no such file or directory\n");
	free(path);
}

char	*handle_tilde(char **input, t_minishell *shell)
{
	char	*temp;
	char	*temp2;
	char	*path;

	path = NULL;
	if (input[1][1] == '/')
	{
		temp = keyword("HOME=", 5, shell->env);
		temp2 = ft_strjoin(temp, "/");
		path = ft_strjoin(temp2, input[1] + 2);
		free(temp);
		free(temp2);
	}
	else
		ft_printf("zsh: no such user or named directory\n");
	return (path);
	// else weird
}

char	*handle_hyphen(char **input, t_minishell *shell)
{
	char *path;

	path = NULL;
	if (!input[1][1] && !input[2])
	{
		ft_printf("%s\n", shell->pre_path);
		path = shell->pre_pre_path;
	}
	return (path);
}

char	**init_cd(char *line, t_minishell *shell)
{
	char	**input;

	input = ft_strsplit(line, ' ', '\t');
	shell->pre_pre_path = shell->pre_path;
	shell->pre_path = shell->current_path;
	// cd - pointer being freed was not allocated
	free(shell->current_path);
	return (input);
}

void	cd(char *line, t_minishell *shell)
{
	char	**input;
	char	*path;
	char	bud[100];

	input = init_cd(line, shell);
	path = NULL;
	if (!input[1] || ft_strequ(input[1], "~") || ft_strequ(input[1], "~/") || ft_strequ(input[1], "$HOME"))
		path = keyword("HOME=", 5, shell->env);
	else if (ft_strequ(input[1], "/"))
		path = ft_strdup("/");
	else if (input[1][0] == '-')
		path = handle_hyphen(input, shell);
	else if (input[1][0] == '~')
		path = handle_tilde(input, shell);
	else
		path = ft_strjoin("./", input[1]);
	if (input[1] && input[2])
		ft_printf("cd: string not in pwd\n");
	else
		move(path);
	shell->current_path = ft_strdup(getcwd(bud, 100));
	free(shell->env->next->next->next->next->next->next->next->next->elem);
	shell->env->next->next->next->next->next->next->next->next->elem = ft_strjoin("PWD=", shell->current_path);
	// ft_printf("current:%s\n", shell->current_path);
	ft_free(input);
}
