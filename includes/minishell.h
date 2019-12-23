/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:58:03 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/22 17:09:28 by hmiyake          ###   ########.fr       */
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
	char			**list;
}					t_minishell;

/*
** cd.c
*/
void				cd(char **list, t_minishell *shell);
/*
** print.c
*/
void				print_env(t_env *env);
void				print_echo(char **list);
int					unmatched(void);
/*
** str_split.c
*/
char				**ft_strsplit2(char const *s, char c, char d);
/*
** env.c
*/
void				set_env(t_minishell *shell);
void				unset_env(t_minishell *shell);
/*
** env2.c
*/
void				update_env(char *key, char *str, t_minishell *shell);
void				save_env(t_env *env);
/*
** real_func.c
*/
void				real_func(t_minishell *shell);
/*
** expansions.c
*/
void				make_it_home(t_minishell *shell, char *temp, int i);
void				handle_dollar(int i, t_minishell *shell);
void				replace_arr(t_minishell *shell, int i, char *arr);
/*
** main.c
*/
char				*keyword(char *word, int size, t_env *env);
t_env				*new_node(char *str);
/*
** str_trim.c
*/
char				*arr_with_term(int size);
char				*ft_strtrim2(char const *s, char a, char b);
char				*trim_chars(char const *s, char a, char b);
/*
** replace.c
*/
int					replace(t_minishell *shell);
/*
** validation.c
*/
int					match_q(char *arr);
int					same_count(char *arr);
int					quot_ver1(char *arr);
int					quot_ver2(char *arr);

#endif
