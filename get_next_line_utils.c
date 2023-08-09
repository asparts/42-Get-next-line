/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:45 by mnummi            #+#    #+#             */
/*   Updated: 2023/07/30 17:16:16 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/**
 * Function to get string length.
*/
size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
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
/**
 * strchr returns returns a pointer to the first occurrence of the
   character searchedChar in the string s.
   Returns NULL if character is not found.
*/

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

char	*ft_join_and_free(char *buffer, char *buffer2)
{
	int		size;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(buffer) + ft_strlen(buffer2);
	str = malloc(sizeof(char) * (size + 2));
	if (!str || !buffer || buffer2)
		return (NULL);
	while (buffer[i] != 0)
	{
		str[i] = buffer[i];
		i++;
	}
	while (buffer2[j] != 0)
	{
		str[i] = buffer2[j];
		i++;
		j++;
	}
	str[size] = 0;
	free(buffer);
	return (str);
}
