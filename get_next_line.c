#include "get_next_line.h" 

int calculnewligne(char *str)
{
	int i ;
    if(!str)
    {
        return 0;
    }
	i = 0;
	while(str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}		
	return (i);
} 
	
char *store_reste(char *s1 , size_t len)
{
    
    char *reste ;
    size_t     slen;
    int j ;

    j = 0;
    slen = strlen(s1);
    reste = (char *)malloc(sizeof(char)* (slen - len) + 1);
    if(!reste)
        free(reste);
        return(NULL);
    while(len + j < slen)
    {
        reste[j] = s1[len + j];
        j++;
    }
    reste[j] = '\0';
    if(reste[0] == '\0')
            {
 
                free(reste);
                return (NULL);
            }
   
    return(reste);
}
char *la_ligne(char *store_line) 
{
	int i ;
	int j ;
	char	*ligne;
	
	j = 0; 
	i = calculnewligne(store_line);
	ligne = (char *)malloc(sizeof(char) * ( i + 2));
	if(!ligne)
	{
		free(ligne);
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
	return (ligne);
}
char *get_next_line(int fd)
{
	char	*buffer;
	static char 	*store_line;
	int			lus;
    size_t     k;

		
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer || fd < 0)
	{ 
	return (NULL);
	}
	lus =  1;
	while(!(ft_strchr(store_line , '\n')) && lus != 0)
	{
		lus = read(fd , buffer , BUFFER_SIZE);
		if(lus == -1)
		{
			free(buffer);
			free(store_line);
			return(NULL);
		}
		buffer[lus] = '\0';
		store_line = ft_strjoin(store_line , buffer);
		
	}
	free(buffer);
	buffer = la_ligne(store_line);
    	k = ft_strlen(buffer);
	store_line = store_reste(store_line , k);
	return(buffer);
}

 

 int main(void)
{
	int fd = open("lorem.txt", O_RDONLY);
	char	*str;
	int		i = 0;
	
	while (i < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	return (0);
}








  
