/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:45 by mnummi            #+#    #+#             */
/*   Updated: 2023/06/29 12:00:47 by mnummi           ###   ########.fr       */
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

char	*ft_strjoin(char const *str1, char const *str2)
{
	int	size;
	char	*str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = ft_strlen(str1) + st_strlen(str2);
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
