#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char *store_reste(char *s1 , size_t len);
char *get_next_line(int fd);
char *la_ligne(char *store_line);
int calculnewligne(char *str);
#endif