/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:45:15 by mnummi            #+#    #+#             */
/*   Updated: 2023/10/10 00:14:34 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/**
 * Function to separate everything after 
 * 	first line from return_str
 * on first while loop go end of the str
*/
char	*get_next_lines_after_return_str(char *return_str)
{
	char	*buffer;
	int		used_char;
	int		len;
	int		not_used_char;

	used_char = 0;
	len = 0;
	not_used_char = 0;
	while (return_str[used_char] != '\n' && return_str[used_char] != '\0')
		used_char++;
	if (return_str[used_char] == '\0')
		return (NULL);
	used_char++;
	while (return_str[used_char + len] != '\0')
		len++;
	buffer = (char *)ft_calloc(len + 1, 1);
	while (return_str[used_char + not_used_char] != '\0')
	{
		buffer[not_used_char] = return_str[used_char + not_used_char];
		not_used_char++;
	}
	return (buffer);
}

/**
 * if read_bytes on error or eof,
 * 		return null
 * join return_str and buffer to tmp
 * and set tmp to return_str
 * if there's new line in buffer
 * set tmp to buffer and return
 * otherwise set null-terminator
 *  to buffer and read from fd to buffer
*/
void	read_line(int fd, char **ret_str, char **buf, int read_bytes)
{
	char	*tmp_str;

	while (1)
	{
		if (read_bytes < 1)
		{
			free(*buf);
			*buf = NULL;
			return ;
		}
		tmp_str = ft_strjoin(*ret_str, *buf);
		free(*ret_str);
		*ret_str = tmp_str;
		if (check_for_new_line(*buf) == 1 || read_bytes != BUFFER_SIZE)
		{
			tmp_str = get_next_lines_after_return_str(*buf);
			free(*buf);
			*buf = tmp_str;
			return ;
		}
		ft_memset(*buf, '\0', BUFFER_SIZE);
		read_bytes = read(fd, *buf, BUFFER_SIZE);
	}
}

/**
 * 
 * If we have new line in buffer, we return that
 * else -> read
 * read_bytes == number of bytes read returned
 * if read_bytes == 0 -> EOF
 * on error read_bytes == -1
 * read_bytes == 0 && return_str[0] == 0
 * ->> EOF and nothing to return from str anymore
 * 
 * use read_line to read from fd
*/
char	*get_next_line(int fd)
{
	static char		*buffer = NULL;
	char			*return_str;
	int				read_bytes;

	return_str = buffer;
	if (return_str == NULL)
		return_str = (char *)ft_calloc(1, 1);
	if (check_for_new_line(buffer) == 1)
		return (new_line_in_buffer(&return_str, &buffer));
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (buffer == NULL)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == -1 || (read_bytes == 0 && return_str[0] == 0))
	{
		free(return_str);
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	read_line(fd, &return_str, &buffer, read_bytes);
	return (return_str);
}
