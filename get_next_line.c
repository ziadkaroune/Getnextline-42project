#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    char *buffer;
    int readf;
    buffer = (char *)malloc(sizeof(char) * 5);
    if(!buffer){
        free(buffer);
        return NULL;
    }
    readf = read(fd , buffer , 4);
    if(!read)
        return NULL;
    return (buffer);
}

int main()
{
    int fd ;
    
    char *next_line; 
    fd = open("texto.txt" , O_RDONLY);
    if(fd == -1)
    {
        return 0;
    }
        
    while(1){
       next_line = get_next_line(fd);
       if(next_line == NULL)
                    break;
        printf("  -- %s" ,   next_line);
        next_line = NULL; 
    }
    close(fd);
    return 0;
}