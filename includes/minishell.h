/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:58:03 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/17 01:03:01 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <signal.h>
# include <dirent.h>

typedef struct		s_env
{
	char			*elem;
	struct s_env	*next;
}					t_env;

typedef struct		s_minishell
{
	t_env			*env;
	char			*current_path;
	char			*pre_path;
}					t_minishell;

/*
** cd.c
*/
void				cd(char **list, t_minishell *shell);

/*
** print.c
*/
void				print_env(t_env *env);
void				print_echo(char **list, t_minishell *shell);

/*
** env.c
*/
void				set_env(char *line, t_minishell *shell);
void				unset_env(char *line, t_minishell *shell);

/*
** real_func.c
*/
void				real_func(char **list, t_minishell *shell);

/*
** main.c
*/
char				*keyword(char *word, int size, t_env *env);
t_env				*new_node(char *str);

#endif
