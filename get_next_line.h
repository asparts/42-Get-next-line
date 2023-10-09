/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:37 by mnummi            #+#    #+#             */
/*   Updated: 2023/10/10 00:17:49 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 8
# endif

char			*get_next_line(int fd);
int				check_for_new_line(char *str);
void			*ft_calloc(size_t elementCount, size_t elementSize);
size_t			ft_strlen(char *str);
void			read_line(int fd, char **ret_str, char **buf, int read_bytes);
char			*get_next_lines_after_return_str(char *return_str);
char			*ft_strjoin(char const *str1, char const *str2);
char			*new_line_in_buffer(char **return_str, char **buffer);

#endif
