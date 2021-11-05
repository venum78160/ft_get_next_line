/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:09:39 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/05 16:27:39 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h> // a enlever !!!!!!
# include <string.h> // a enlever !!!!!
# include <errno.h> // a enlever !!!!!!

//prototype
char	*get_next_line(int fd);
char	*ft_add_buffer(int fd, char *buffer);
char	*ft_reset_buffer(char *buffer, int sizeline);
char	*ft_strjoin(char *buffer, char *add);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, unsigned int size);
char	*ft_strdup(char *src);
char	*ft_strchr(const char	*string, int searchedChar);

#endif