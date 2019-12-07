/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:58:03 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/06 20:53:27 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

char	**env;
char	*current_path;
char	*last_path;
char	*last_last_path;

/*
** cd.c
*/
void	cd(char *line);

/*
** print.c
*/
void	print_env(void);
void	print_echo(char *line);

/*
** main.c
*/
char	*keyword(char *word, int size);

#endif
