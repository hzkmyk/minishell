/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:23:46 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/21 22:02:45 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**save_environ(t_minishell *shell)
{
	char	**environ;
	t_env	*temp;
	int		count;
	int		i;

	temp = shell->env;
	count = 0;
	i = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	environ = (char **)malloc(sizeof(char *) * (count + 1));
	environ[count] = NULL;
	temp = shell->env;
	while (i < count)
	{
		environ[i] = ft_strdup(temp->elem);
		i++;
		temp = temp->next;
	}
	return (environ);
}

int		search_for_command2(struct dirent *readd, t_minishell *shell,
char *path, char **environ)
{
	char	*temp;
	char	*temp2;

	if (ft_strequ(readd->d_name, shell->list[0]))
	{
		temp = ft_strjoin(path, "/");
		temp2 = ft_strjoin(temp, shell->list[0]);
		execve(temp2, shell->list, environ);
		return (1);
	}
	return (0);
}

void	search_for_command(t_minishell *shell, char **environ)
{
	char			*temp;
	char			**paths;
	int				i;
	DIR				*dir;
	struct dirent	*readd;

	temp = keyword("PATH=", 5, shell->env);
	paths = ft_strsplit(temp, ':', ' ');
	ft_strdel(&temp);
	i = 0;
	while (paths[i])
	{
		if ((dir = opendir(paths[i])))
		{
			while ((readd = readdir(dir)))
			{
				if (search_for_command2(readd, shell, paths[i], environ))
					return ;
			}
			closedir(dir);
		}
		i++;
	}
	ft_printf("zsh: command not found: %s\n", shell->list[0]);
	exit(EXIT_FAILURE);
}

void	child(t_minishell *shell)
{
	char	**environ;

	environ = save_environ(shell);
	if (shell->list[0][0] == '/')
		execve(shell->list[0], shell->list, environ);
	search_for_command(shell, environ);
}

void	real_func(t_minishell *shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		ft_printf("Fork not successful =(\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		child(shell);
	else
		waitpid(pid, &status, 0);
}
