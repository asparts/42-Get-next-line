/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:45:15 by mnummi            #+#    #+#             */
/*   Updated: 2023/09/15 18:09:05 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
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
	if(read_bytes == -1 || (read_bytes == 0 && return_str[0] == 0))
	{
		free(return_str);
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	read_line(fd, &return_str, &buffer, read_bytes);
	return (return_str);
}
