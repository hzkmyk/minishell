/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:20:33 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/22 17:00:56 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		print_env(t_env *env)
{
	while (env)
	{
		ft_printf("%s\n", env->elem);
		env = env->next;
	}
}

void		print_echo(char **list)
{
	int		i;
	int		space;

	i = 1;
	space = 0;
	while (list[i])
	{
		if (space)
			ft_printf(" ");
		ft_printf(list[i]);
		space = 1;
		i++;
	}
	ft_printf("\n");
}

int			unmatched(void)
{
	ft_printf("Unmatched \'.\n");
	return (1);
}
