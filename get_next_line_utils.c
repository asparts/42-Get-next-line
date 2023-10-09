/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:45 by mnummi            #+#    #+#             */
/*   Updated: 2023/09/15 18:05:53 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * return 1 if new line exist, 0 if it doesnt
*/
int check_for_new_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
		while(str[i] != '\0')
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
		return 0;
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(elementSize * elementCount + 1);
	if (!p)
		return (NULL);
	while (i <= elementSize)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}
char	*new_line_in_buffer(char **return_str, char **buffer)
{
	char	*tmp_str;

	tmp_str = ft_strjoin(*return_str, "\0");
	*buffer = get_next_lines_after_return_str(*return_str);
	free(*return_str);
	*return_str = tmp_str;
	return (tmp_str);
}

/**
 * Joining strings together
 * if str1 (or new_str) ends with '\n', 
 * str2 is not being joined and
 * only str1 is being returned
*/
char    *ft_strjoin(char const *str1, char const *str2)
{
        char    *new_str;
        int             str1_size;
        int             str2_size;

        if (str1 == NULL || str2 == NULL)
                return (NULL);
        str1_size = ft_get_line_len((char *)str1);
        str2_size = ft_get_line_len((char *)str2);
        new_str = (char *)ft_calloc(str1_size + str2_size + 1, 1);
        if (!new_str)
                return (NULL);
        ft_memcpy(new_str, str1, str1_size);
        if (check_for_new_line(new_str) == 1)
                return (new_str);
        ft_memcpy(&new_str[str1_size], str2, str2_size);
        return (new_str);
}
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
void read_line(int fd, char **return_str, char **buffer, int read_bytes)
{
	char	*tmp_str;

	while (1)
	{
		if (read_bytes < 1)
		{
			free(*buffer);
			*buffer = NULL;
			return ;
		}
		tmp_str = ft_strjoin(*return_str, *buffer);
		free(*return_str);
		*return_str = tmp_str;
		if (check_for_new_line(*buffer) == 1 || read_bytes != BUFFER_SIZE)
		{
			tmp_str = get_next_lines_after_return_str(*buffer);
			free(*buffer);
			*buffer = tmp_str;
			return ;
		}
		ft_memset(*buffer, '\0', BUFFER_SIZE);
		read_bytes = read(fd, *buffer, BUFFER_SIZE);
	}
}
/**
 * Function to get line length.
*/
size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
           return (i + 1);
		i++;

	}
	return (i);
}