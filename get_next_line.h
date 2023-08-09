/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:37 by mnummi            #+#    #+#             */
/*   Updated: 2023/07/30 16:47:19 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 5
# endif

char			*get_next_line(int fd);
char			*read_file(int fd, char *res);
char			*ft_join_and_free(char *buffer, char *buffer2);
char			*ft_next_line(char *buffer);
char			*ft_read_line(char *buffer);
void			*ft_strchr(const char *s, int searchedChar);

size_t			ft_strlen(char *str);
void			*ft_calloc(size_t elementCount, size_t elementSize);

#endif
