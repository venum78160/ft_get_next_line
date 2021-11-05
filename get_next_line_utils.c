/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:12:43 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/05 16:27:38 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		taill;
	char	*cpy;

	taill = 0;
	while (src[taill])
		taill++;
	cpy = (void *)malloc(sizeof(*cpy) * (taill + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < taill)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strchr(const char	*string, int searchedChar)
{
	int		i;
	char	*str;

	i = 0;
	searchedChar = (char) searchedChar;
	str = (char *) string;
	if (string[0] == '\0' && searchedChar == '\0')
		return (NULL);
	if (string[0] == '\0')
		return (NULL);
	if (searchedChar == '\0')
	{
		while (str[i] != '\0')
			i++;
		return (str + i);
	}
	while (str[i] != '\0')
	{
		if (str[i] == searchedChar)
			return (str + i);
		i++;
	}
	return (NULL);
}
