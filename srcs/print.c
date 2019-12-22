/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:20:33 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/21 22:55:27 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_env(t_env *env)
{
	while (env)
	{
		ft_printf("%s\n", env->elem);
		env = env->next;
	}
}

void	print_echo(char **list)
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

char		*arr_with_term(int size)
{
	char	*str;
	
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	return (str);
}

char	*ft_strtrim2(char const *s, char a, char b)
{
	char	*str;
	int		len;

	if (!s)
		return (0);
	while (*s == a || *s == b)
		s++;
	len = ft_strlen(s);
	while (len > 0 && (s[len - 1] == a || s[len - 1] == b))
		len--;
	str = arr_with_term(len);
	ft_strncpy(str, s, len);
	return (str);
}

char	*trim_chars(char const *s, char a, char b)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	len = ft_strlen(s);
	while (s[++i])
	{
		if (s[i] == a || s[i] == b)
			len--;
	}
	i = 0;
	str = arr_with_term(len);
	while (i < len && s[j])
	{
		if (s[j] != a && s[j] != b)
		{
			str[i] = s[j];
			i++;
		}
		j++;
	}	
	return (str);
}