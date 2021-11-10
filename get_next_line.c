/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:28:36 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/10 17:07:29 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *buffer, char *add)
{
	int		i;
	char	*new;
	int		t;
	int		j;

	t = ft_strlen(buffer) + ft_strlen(add) + 1;
	new = malloc(sizeof(char) * t);
	if (!new)
		return (NULL);
	i = -1;
	j = 0;
	while (buffer[++i])
		new[i] = buffer[i];
	while (add[j])
		new[i++] = add[j++];
	new[i] = '\0';
	free (buffer);
	return (new);
}

char	*ft_reset_buffer(char *buffer, int sizeline)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = malloc(sizeof(char) * (ft_strlen(buffer) - sizeline + 1));
	if (!line)
		return (NULL);
	while (i < sizeline)
		i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free (buffer);
	return (line);
}

char	*ft_add_buffer(int fd, char *buffer)
{
	char	*add;
	int		tete;

	add = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!add)
		return (NULL);
	tete = 1;
	while (!ft_strchr(buffer, '\n') && tete != 0)
	{
		tete = read(fd, add, BUFFER_SIZE);
		if (tete < 0)
		{
			free (add);
			free (buffer);
			return (NULL);
		}
		add[tete] = '\0';
		buffer = ft_strjoin(buffer, add);
	}
	free (add);
	return (buffer);
}

char	*new_line(char *buffer)
{
	int		newbuf;
	char	*line;

	if (buffer == NULL)
		return (NULL);
	if (ft_strchr(buffer, '\n') == NULL)
		newbuf = 0;
	else
		newbuf = ft_strlen(ft_strchr(buffer, '\n')) - 1;
	line = malloc(sizeof(char) * (ft_strlen(buffer) - newbuf) + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, (ft_strlen(buffer) - newbuf) + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || fd > 255 ||BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = ft_add_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = new_line(buffer);
	buffer = ft_reset_buffer(buffer, ft_strlen(line));
	if (line[0] == '\0')
	{
		free (line);
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	return (line);
}
