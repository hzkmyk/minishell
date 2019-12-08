/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:02:12 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/07 16:22:56 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd(char *line, t_minishell *shell)
{
	char	**temp;
	char	*path;
	char	bud[100];
	char	*temp2;
	char	*temp3;

	temp = ft_strsplit(line, ' ', '\t');
	shell->last_last_path = shell->last_path;
	shell->last_path = shell->current_path;
	path = NULL;
	if (!temp[1] || temp[1][0] == '/')
		path = keyword("HOME=", 5, shell);
	else if (temp[1][0] == '-')
	{
		if (!temp[1][1] && !temp[2])
		{
			ft_printf("%s\n", shell->last_path);
			path = shell->last_last_path;
		}
	}
	else if (temp[1][0] == '~')
	{
		if (!temp[1][1] || temp[1][1] == '/')
		{
			if (!temp[1][2])
				path = keyword("HOME=", 5, shell);
			else
			{
				temp2 = keyword("HOME=", 5, shell);
				temp3 = ft_strjoin(temp2, "/");
				path = ft_strjoin(temp3, temp[1] + 2);
				free(temp2);
				free(temp3);
			}
		}
		else if (temp[1][1])
		{
			ft_printf("zsh: no such user or named directory\n");
			return;
		}
	}
	else if (ft_strequ(temp[1], "$HOME"))
		path = keyword("HOME=", 5, shell);
	else
		path = ft_strjoin("./", temp[1]);
	if (temp[1] && temp[2])
		ft_printf("cd: string not in pwd\n");
	else
	{
		if (chdir(path) == -1)
			ft_printf("cd: no such file or directory\n");
	}
	free(path);
	shell->current_path = ft_strdup(getcwd(bud, 100));
	free(shell->env[8]);
	shell->env[8] = ft_strjoin("PWD=", ft_strdup(shell->current_path));
	ft_printf("current:%s\n", shell->current_path);
}
