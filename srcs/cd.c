/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:02:12 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/05 22:02:54 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd(char *line)
{
	char	**temp;
	char	*path;

	temp = ft_strsplit(line, ' ', '\t');
	if (temp[1][0] == '/')
	{
		chdir(keyword("HOME", 4));
		path = temp[1];
	}
	// here
	else if (temp[1][0] == '~')
	{
		chdir(keyword("HOME", 4));
		if (temp[1][1] == '/')
			path = temp[1] + 2;
		else if (temp[1][1])
			ft_printf("zsh: no such user or named directory\n");
	}
	else
		path = ft_strjoin("./", temp[1]);
	// write(0, path, ft_strlen(path));
	if (temp[2])
		ft_printf("cd: string not in pwd: ..\n");
	else
	{
		if (chdir(path) == -1)
			ft_printf("cd: no such file or directory\n");
	}
}