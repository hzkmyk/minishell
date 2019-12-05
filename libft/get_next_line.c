/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 20:09:27 by hmiyake           #+#    #+#             */
/*   Updated: 2019/08/12 15:07:40 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		new_line_checker(int fd, char **line, char **joyce)
{
	int		i;
	char	*temp;

	i = 0;
	while (joyce[fd][i] != '\n' && joyce[fd][i] != '\0')
		i++;
	if (joyce[fd][i] == '\n')
	{
		*line = ft_strsub(joyce[fd], 0, i);
		temp = ft_strdup(joyce[fd] + i + 1);
		ft_strdel(&joyce[fd]);
		if (*temp)
			joyce[fd] = ft_strdup(temp);
		ft_strdel(&temp);
	}
	else
	{
		*line = ft_strdup(joyce[fd]);
		ft_strdel(&joyce[fd]);
	}
	return (1);
}

void	temp_to_joyce(int fd, char **joyce, char *buff)
{
	char *temp;

	temp = ft_strjoin(joyce[fd], buff);
	ft_strdel(&joyce[fd]);
	joyce[fd] = ft_strdup(temp);
	ft_strdel(&temp);
}

int		get_next_line(const int fd, char **line)
{
	int			readsize;
	static char	*joyce[1024];
	char		buff[BUFF_SIZE + 1];

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	while ((readsize = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (joyce[fd] == NULL)
			joyce[fd] = ft_strnew(0);
		buff[readsize] = '\0';
		temp_to_joyce(fd, joyce, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (readsize < 0)
		return (-1);
	if (readsize == 0 && joyce[fd] == NULL)
	{
		if (*line)
			ft_strdel(line);
		return (0);
	}
	return (new_line_checker(fd, line, joyce));
}
