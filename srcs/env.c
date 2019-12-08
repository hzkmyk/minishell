/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:23:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/07 23:40:46 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_env(char *line, t_minishell *shell)
{
	int		i;
	char	**input;
	char	*temp;
	char	*temp2;
	t_env	*tenv;
	t_env	*t;

	i = 0;
	input = ft_strsplit(line, ' ', '\t');
	temp2 = NULL;
	t = shell->env;
	if (!input[1])
	{
		print_env(shell->env);
		return ;
	}
	// memoryleak below
	temp = ft_strjoin(ft_strdup(input[1]), "=");
	if (input[2])
	{
		temp2 = ft_strjoin(temp, input[2]);
		free(temp);
	}
	while (t->next)
		t = t->next;
	tenv = (t_env *)malloc(sizeof(t_env));
	tenv->elem = !input[2]? temp: temp2;
	// ft_printf("elem:%s\n", t->elem);
	t->next = tenv;
	tenv->next = NULL;
}
