/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:20:33 by hmiyake           #+#    #+#             */
/*   Updated: 2019/12/20 00:53:32 by hmiyake          ###   ########.fr       */
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


static int	getnumofw(const char *s, char c, char d)
{
	int		i;
	int		count;
	int		quote;

	i = 0;
	count = 0;
	quote = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'' || s[i] == '\"')
			quote++;
		if (s[i] != c && s[i] != d && (quote != 1 && (s[i + 1] == c ||
		s[i + 1] == d || s[i + 1] == '\0')))
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
	while (s[i] != '\0' && ((s[i] != c && s[i] != d) || ((s[i] == c && (quote == 1 || quote % 2)) || (s[i] == d && (quote == 1 || quote % 2)))))
	{
		if (s[i] == '\'' || s[i] == '\"')
			quote++;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	if (str)
	{
		while (j < i)
		{
			str[j] = s[j];
			j++;
		}
	}
	return (str);
}

char		**ft_strsplit2(char const *s, char c, char d)
{
	char	**array;
	int		i;
	int		now;
	int		quote;

	i = 0;
	quote = 0;
	if (!s)
		return (0);
	now = getnumofw(s, c, d);
	array = (char **)malloc(sizeof(char *) * (now + 1));
	array[now] = NULL;
	if (array)
	{
		while (i < now)
		{
			if (*s == '\'' || *s == '\"')
				quote++;
			while (*s == c || *s == d)
				s++;
			if (*s != '\0')
				array[i] = mallocandcopy(s, c, d);
			while (*s != '\0' && ((*s != c && *s != d) || (*s == c && quote == 1) || (*s == d && quote == 1)))
			{
				if (*s == '\'' || *s == '\"')
					quote++;
				s++;
			}
			i++;
			if (quote == 2)
				quote = 0;
		}
	}
	return (array);
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
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		ft_strncpy(str, s, len);
		str[len] = '\0';
	}
	return (str);
}

char	*ft_strtrim3(char const *s, char a, char b)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == a || s[i] == b)
			len--;
		i++;
	}
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (str)
	{
		while (i < len && s[j])
		{
			if (s[j] != a && s[j] != b)
			{
				str[i] = s[j];
				i++;
			}
			j++;
		}	
	}
	return (str);
}