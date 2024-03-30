#include "get_next_line.h" 
 
char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
    {
		return (NULL);
    }

	while (str[i])
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *buffer, char *content)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!buffer)
	{
	    
		return (ft_strdup(content));
	}
	if (!content)
	{ 
		return (ft_strdup(buffer));
	}
	i = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(buffer)
				+ ft_strlen(content)) + 1);
	if (!result)
		return (NULL);
	while ( buffer[i])
	{
		result[i] = buffer[i];
		i++;
	}
	j = 0;
	while (content && content[j])
		result[i++] = content[j++];
	result[i] = '\0';
	free(buffer);
	return (result);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
 
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t calculnewligne(char *str)
{
	size_t  i;

    i = 0;
 
     while(str[i] != '\0' && str[i] != '\n')
    {
	    i++; 
    }
		
	return (i);
}

char *store_reste(char *s1)
{
    char *reste ;
    size_t     slen;
    size_t len;
    int j ;
    
    reste = NULL;
    if(!s1 || s1[0] == '\0' )
    {
    	free(s1);
    	return (NULL);
    }
    
    len = calculnewligne(s1) + 1;
    j = 0;
    slen = ft_strlen(s1);

   

    reste = (char *)malloc(sizeof(char) * (slen - len + 1));
    if(!reste){ 
        return(NULL);
        }
    while(len + j < slen)
    {
        reste[j] = s1[len + j];
        j++;
    }
    reste[j] = '\0';
    free(s1);
    return(reste);
}

char *la_ligne(char *store_line) 
{
	int i ;
	int j ;
	char	*ligne;
	
	j = 0; 
	if(store_line[j] == '\0')
	{
		
		return (free(store_line) , NULL);
	}
	i = calculnewligne(store_line);
	ligne = (char *)malloc(sizeof(char) * ( i + 2));
	if(!ligne)
	{
		return (NULL);
	}
	while(i > 0)
	{
		ligne[j] = store_line[j];
		j++;
		i--;
	}
 	ligne[j] = '\n';
 	ligne[j + 1] = '\0';
     if (!ligne[0])
	{
	 
	 free(store_line);
        free(ligne);
        return NULL;
	}

	return (ligne);
}

char *get_next_line(int fd)
{
    char *buffer;
    static char *store_line ;  
    int lus;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return NULL;
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
    {
        return NULL;
      }
    lus = 1;
    while (!(ft_strchr(store_line, '\n')) && lus != 0)
    {
        lus = read(fd, buffer, BUFFER_SIZE);
        if (lus < 0)
        {
            free(buffer); 
            return NULL;
        }
     
        buffer[lus] = '\0';
        store_line = ft_strjoin(store_line, buffer);
    
    }
    
    free(buffer); 
    buffer = la_ligne(store_line);
    store_line = store_reste(store_line);
    return buffer;
}
 
 
 
