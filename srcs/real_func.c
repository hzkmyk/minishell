/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:23:46 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/16 23:08:25 by hmiyake          ###   ########.fr       */
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

void	search_for_command(t_minishell *shell, char **list, char **environ)
{
	char			*key;
	char			**paths;
	int				i;
	DIR				*dir;
	struct dirent	*readd;

	key = keyword("PATH=", 5, shell->env);
	paths = ft_strsplit(key, ':', ' ');
	i = 0;
	while (paths[i])
	{
		if (!(dir = opendir(paths[i])))
		{
			i++;
			continue;
		}
		while ((readd = readdir(dir)))
		{
			if (ft_strequ(readd->d_name, list[0]))
			{
				char *temp;
				temp = ft_strjoin(paths[i], "/");
				char *temp2;
				temp2 = ft_strjoin(temp, list[0]);
				execve(temp2, list, environ);
				return ;
			}
		}
		i++;
		closedir(dir);
	}
	ft_printf("zsh: command not found: %s\n", list[0]);
}

void	child(t_minishell *shell, char **list)
{
	char	**environ;

	environ = save_environ(shell);
	if (list[0][0] == '/')
		execve(list[0], list, environ);
	search_for_command(shell, list, environ);
}

void	 real_func(char **list, t_minishell *shell)
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
		child(shell, list);
	else
		waitpid(pid, &status, 0);
}
