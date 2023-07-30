/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:45:15 by mnummi            #+#    #+#             */
/*   Updated: 2023/07/30 16:33:14 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// allocating memory if res doesnt exist yet. 
// In while loop while byte_red is greater than zero 
// and we're not in end of the file, 
//    we read from fd to buffer amount determined in BUFFER_SIZE
// buffer[byte_read] is being set to 0 to prevent memory leaks.
// After that, we join res and buffer together and 
//    free original res from memory in that same join_and_free function.
char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		res = ft_join_and_free(res, buffer, 1);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

// removing the line from buffer (so we can get new next line)
// in first while, finding length of first line
// if end of line == \0 we return NULL
//allocate memory for the first line (+1 for safety bcuz i is initialized to 0)
// in second while, remove the first line from buffer and return it
char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i +1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i + 1];
	free(buffer);
	return (line);
}

// for returning / reading the line from buffer
// returning NULL if there's no line
// with while, loop till we are at end of the line
// allocating memory for the line with ft_calloc
// copy line from buffer to char *loine
// if end of line on buffer == \0 or \n, replace it by \n on line
// lastly, return the line
char	*ft_read_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer [i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
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
