/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:45 by mnummi            #+#    #+#             */
/*   Updated: 2023/10/10 00:56:19 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(elementSize * elementCount + 1);
	if (!p)
		return (NULL);
	while (i < elementSize * elementCount)
	{
		p[i] = 0;
		i++;
	}
	return ((void*)p);
}

/**
 * Joining strings together
 * if str1 (or new_str) ends with '\n', 
 * str2 is not being joined and
 * only str1 is being returned
*/
char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*new_str;
	int		str1_size;
	int		str2_size;

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
 * Function to get line length.
*/
size_t	ft_get_line_len(char *str)
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cc;
	size_t			i;

	cc = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		cc[i] = c;
		i++;
	}
	return (s = cc);
}
