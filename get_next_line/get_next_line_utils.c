/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:22:11 by snakita           #+#    #+#             */
/*   Updated: 2021/11/01 17:22:12 by snakita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = len;
	if (len > ft_strlen(s))
		i = ft_strlen(s);
	str = (char *)malloc(i + 1);
	if (str)
	{
		i = 0;
		while (start-- > 0 && *s)
			s++;
		while (*s && i < len)
		{
			str[i] = *s++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen((char *)s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str)
	{
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		j = -1;
		while (s2[++j])
			str[j + i] = s2[j];
		str[j + i] = '\0';
		free((void *)s1);
		return (str);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != (char)c)
			i++;
		if (s[i] == (char) c)
			return ((char *) s + i);
	}
	return (NULL);
}
