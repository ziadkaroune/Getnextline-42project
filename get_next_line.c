/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkaroune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:05:19 by zkaroune          #+#    #+#             */
/*   Updated: 2024/03/30 21:05:22 by zkaroune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	calculnewligne(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*store_reste(char *s1)
{
	char	*reste;
	size_t	slen;
	size_t	len;
	int		j;

	if (!s1 || !s1[0])
	{
		free(s1);
		return (NULL);
	}
	len = calculnewligne(s1) + 1;
	j = 0;
	slen = ft_strlen(s1);
	reste = (char *)malloc(sizeof(char) * (slen - len + 1));
	if (!reste)
		return (NULL);
	while (len + j < slen)
	{
		reste[j] = s1[len + j];
		j++;
	}
	reste[j] = '\0';
	free(s1);
	return (reste);
}

char	*la_ligne(char *str)
{
	char	*ligne;
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (NULL);
	i = calculnewligne(str) + 1;
	ligne = (char *)malloc(sizeof(char) * i + 1);
	if (!ligne)
		return (NULL);
	j = 0;
	while (i > 0)
	{
		ligne[j] = str[j];
		j++;
		i--;
	}
	ligne[j] = '\n';
	ligne[j++] = '\0';
	return (ligne);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*store_line;
	int			lus;
	
	lus = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	
	while (!(ft_strchr(store_line, '\n')) && lus != 0)
	{
		lus = read(fd, buffer, BUFFER_SIZE);
		if (lus == -1)
		{
			free(buffer);
			free(store_line);
			store_line = NULL;
			return (NULL);
		}
		buffer[lus] = '\0';
		store_line = ft_strjoin(store_line, buffer);
	}
	free(buffer);
	buffer = la_ligne(store_line);
	store_line = store_reste(store_line);
	return (buffer);
}
