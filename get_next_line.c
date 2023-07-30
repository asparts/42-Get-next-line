/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:45:15 by mnummi            #+#    #+#             */
/*   Updated: 2023/07/27 16:36:18 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int	byte_read;

	// allocate memory if res doesnt exist yet
	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		// while not end of file
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// set to 0 to prevent memory leak
		buffer[byte_read] = 0;
		res = ft_join_and_free(res, buffer, 1);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*ft_next_line(char *buffer)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	// find len of first line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if end of line == \0, return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// length of file - length of firstline +1
	line = ft_calloc((ft_strlen(buffer) - i +1), sizeof(char));
	i++;
	j = 0;
	// line == buffer
	while (buffer[i])
		line[j++] = buffer[i+1];
	free(buffer);
	return (line);
}
// return line
char	*ft_read_line(char *buffer)
{
	char	*line;
	int	i;

	i = 0;
	// return NULL if there's no line
	if (!buffer[i])
		return (NULL);
	// go to end of line
	while (buffer[i] && buffer [i] != '\n')
		i++;
	// allocate memory for the line
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// line == buffer
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// if end of line on buffer == \0 or \n, replace it by \n on line
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_read_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
