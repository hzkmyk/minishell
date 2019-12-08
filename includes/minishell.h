/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:58:03 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/07 20:05:21 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

typedef struct s_minishell
{
	char	**env;
	char	*current_path;
	char	*pre_path;
	char	*pre_pre_path;
}				t_minishell;

/*
** cd.c
*/
void	cd(char *line, t_minishell *shell);

/*
** print.c
*/
void	print_env(t_minishell *shell);
void	print_echo(char *line, t_minishell *shell);

/*
** env.c
*/
void	set_env(char *line, t_minishell *shell);

/*
** main.c
*/
char	*keyword(char *word, int size, t_minishell *shell);

#endif
