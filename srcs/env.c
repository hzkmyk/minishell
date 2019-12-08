/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:23:38 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/07 20:05:44 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	set_env(char *line, t_minishell *shell)
// {
// 	int		i;
// 	char	**input;
// 	char	*temp;
// 	char	*temp2;

// 	i = 0;
// 	input = ft_strsplit(line, ' ', '\t');
// 	while (shell->env[i])
// 		i++;
// 	temp = ft_strjoin(ft_strdup(input[1]), "=");
// 	temp2 = ft_strjoin(temp, input[2]);
// 	free(temp);
// 	shell->env[i] = temp2;
// 	free(temp2);
// 	i++;
// 	shell->env[i] = (char *)malloc(sizeof(char));
// 	shell->env[i] = NULL;
// }