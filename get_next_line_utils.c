/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:45 by mnummi            #+#    #+#             */
/*   Updated: 2023/07/27 16:37:56 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int	size;
	char	*str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = ft_strlen(str1) + ft_strlen(str2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str || !str1 || str2)
		return (NULL);
	while (str1[i] != 0)
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j] != 0)
	{
		str[i] = str2[j];
		i++;
		j++;
	}
	str[size] = 0;
	return (str);
}
void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*p;

	p = malloc(elementSize * elementCount);
	if(!p)
		return (NULL);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	char	*c = s;
	size_t	i;

	i = 0;
	while (i <= n)
	{
		c[i] = '\0';
		i++;
	}
}

void	*ft_strchr(const char *s, int searchedChar)
{
	char	*str;

	str = (char *)s;
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	else
		return (NULL);
}
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
		res = ft_free(res, buffer);
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
char	*ft_free(char *buffer, char *buffer2)
{
	char	*temp;

	temp = ft_strjoin(buffer, buffer2);
	free(buffer);
	return (temp);
}
