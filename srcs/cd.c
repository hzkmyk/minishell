/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:02:12 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/06 21:57:25 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// need to handle expansion

void	cd(char *line)
{
	char	**temp;
	char	*path;
	char	bud[100];
	char	*temp2;
	char	*temp3;

	temp = ft_strsplit(line, ' ', '\t');
	last_last_path = last_path;
	last_path = current_path;
	path = NULL;
	if (!temp[1] || temp[1][0] == '/')
		path = keyword("HOME=", 5);
	else if (temp[1][0] == '-')
	{
		if (!temp[1][1] && !temp[2])
		{
			ft_printf("%s\n", last_path);
			path = last_last_path;
		}
	}
	else if (temp[1][0] == '~')
	{
		if (!temp[1][1] || temp[1][1] == '/')
		{
			if (!temp[1][2])
				path = keyword("HOME=", 5);
			else
			{
				temp2 = keyword("HOME=", 5);
				temp3 = ft_strjoin(temp2, "/");
				path = ft_strjoin(temp3, temp[1] + 2);
				write(0, path, ft_strlen(path));
				write(0, "\n", 1);
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
	current_path = ft_strdup(getcwd(bud, 100));
	free(env[8]);
	env[8] = ft_strjoin("PWD=", ft_strdup(current_path));
	write(0, "current:", 8);
	write(0, current_path, ft_strlen(current_path));
	write(0, "\n", 1);
}
