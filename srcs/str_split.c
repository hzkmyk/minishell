/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:54:47 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/21 23:52:46 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	getnumofw(const char *s, char c, char d)
{
	int		i;
	int		count;
	int		quote;

	i = 0;
	count = 0;
	quote = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			quote++;
		if (s[i] != c && s[i] != d && ((quote != 1 && (s[i + 1] == c ||
		s[i + 1] == d)) || s[i + 1] == '\0'))
			count++;
		i++;
		if (quote == 2)
			quote = 0;
	}
	return (count);
}

static char	*mallocandcopy(const char *s, char c, char d)
{
	int		i;
	int		j;
	char	*str;
	int		quote;

	i = 0;
	j = 0;
	quote = 0;
	while (s[i] != '\0' && ((s[i] != c && s[i] != d) ||
	((s[i] == c && (quote == 1 || quote % 2)) ||
	(s[i] == d && (quote == 1 || quote % 2)))))
	{
		if (s[i] == '\'' || s[i] == '\"')
			quote++;
		i++;
	}
	str = arr_with_term(i);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	return (str);
}

int			quote_count(char const *s, int quote)
{
	if (quote == 2)
		quote = 0;
	if (*s == '\'' || *s == '\"')
		quote++;
	return (quote);
}

char		**init_array(int now)
{
	char	**array;

	array = (char **)malloc(sizeof(char *) * (now + 1));
	array[now] = NULL;
	return (array);
}

char		**ft_strsplit2(char const *s, char c, char d)
{
	char	**array;
	int		i;
	int		quote;
	int		now;

	i = -1;
	quote = 0;
	now = getnumofw(s, c, d);
	array = init_array(now);
	while (++i < now)
	{
		quote = quote_count(s, quote);
		while (*s == c || *s == d)
			s++;
		if (*s != '\0')
			array[i] = mallocandcopy(s, c, d);
		while (*s != '\0' && ((*s != c && *s != d) || (*s == c && quote == 1)
		|| (*s == d && quote == 1)))
		{
			if (*s == '\'' || *s == '\"')
				quote++;
			s++;
		}
	}
	return (array);
}
