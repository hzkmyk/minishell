/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:02:12 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/20 23:41:27 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	move(char *path)
{
	if (chdir(path) == -1)
		ft_printf("cd: no such file or directory: %s\n", path);
}

char	*handle_hyphen(char **input, t_minishell *shell)
{
	char *path;

	if (!input[1][1] && !input[2])
	{
		path = shell->pre_path;
		if(path == NULL)
			path = shell->current_path;
	}
	else
		path = NULL;
	ft_printf("%s\n", path);
	return (path);
}

void	init_cd(t_minishell *shell)
{
	if (shell->pre_path)
	{
		free(shell->pre_path);
		shell->pre_path = NULL;
	}
	shell->pre_path = shell->current_path;
}

void	cd(char **list, t_minishell *shell)
{
	char	*path;
	char	bud[100];

	if (list[1][0] == '-')
		path = handle_hyphen(list, shell);
	else
		path = list[1];
	if (list[1] && list[2])
		ft_printf("cd: string not in pwd: %s\n", list[1]);
	else
		move(path);
	init_cd(shell);
	shell->current_path = ft_strdup(getcwd(bud, 100));
	free(shell->env->next->next->next->next->next->next->next->next->elem);
	shell->env->next->next->next->next->next->next->next->next->elem = ft_strjoin("PWD=", shell->current_path);
}
