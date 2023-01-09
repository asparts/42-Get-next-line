
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *res);
char	*ft_free(char *buffer, char *buffer2);

size_t	ft_strlen(char *str);
char	*ft_strjoin(char const *str1, char const *str2);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);

#endif
