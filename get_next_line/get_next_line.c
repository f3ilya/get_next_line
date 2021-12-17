/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:21:43 by snakita           #+#    #+#             */
/*   Updated: 2021/11/01 17:21:45 by snakita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, char *str)
{
	int		i;
	char	*buf;

	i = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!(ft_strchr(str, '\n')) && i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		if (!str)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*ft_zapis(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	return (line);
}

char	*ft_ostatok(char *str)
{
	size_t	i;
	char	*rez;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	rez = ft_substr(str, i, ft_strlen(str) - i);
	free(str);
	return (rez);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str = ft_read_fd(fd, str);
	if (!str || str[0] == '\0')
	{
		free(str);
		str = 0;
		return (NULL);
	}
	line = ft_zapis(str);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (0);
	}
	str = ft_ostatok(str);
	return (line);
}
