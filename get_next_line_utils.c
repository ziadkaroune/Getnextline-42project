#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
    if(!s)
            return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	j;
	size_t	i;
	char	*unions;

	if (!s1 && !s2)
		return (NULL);
	unions = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!unions)
		return (NULL);

	while (j < ft_strlen(s1))
	{
		unions[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i]) 
	{
		unions[j + i] = s2[i];
		i++;
	}
	unions[i + j] = '\0';
	return (unions);
}
