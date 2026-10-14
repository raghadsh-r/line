/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralshraw <ralshraw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:04:47 by ralshraw          #+#    #+#             */
/*   Updated: 2026/10/14 14:24:41 by ralshraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define  BUFFER_SIZE 42
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int	cheaknew_line(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);


}

char *save_newline(int index , char *str)
{
    char *line;
    int i = 0;
    line = malloc (index + 2);
    while(i < index)
    {
        line[i] = str[i];
        i++;
    }
    line[i] = str[i]; 
    line[++i] = '\0';
    return(line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens2;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lens2 = ft_strlen(s2);
	str = malloc((ft_strlen(s1) + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}


int cheakfile(char *file, int fd)
{
    int index;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || !file)
    {
        free(file);
        return (-2);
    }  temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
    while (numofword && flag)
    {
        
    }
    index = cheaknew_line(file,'\n');
    return(index);
    
}
char *solve(char *file, int index)
{
    char *str;
    int i;

    i = 0;
    str = malloc(index + 2);
    while(i <= index)
    {
        str[i] = file[i];
        i++;       
    }
    str[i] = '\0';
    return(str);
}
char *filesave(char * file,int index)
{
    int len ;
    int i;

    i = 0;
    index++;
    len = ft_strlen(file);
    char *str = malloc(len - index);
    while(file[index])
    {
        str[i] = file[index];
        i++;
        index++;
    }
    free(file);
    str[i] = '\0';
    return (str[i]);
}index (temp);
char *get_next_line(int fd)
{
    static char *file;
    int index;
    int numberofchar;
    char *len;
    char *temp;
    index = cheakfile(file,fd);
    if(index == -2)
        return (NULL);
    if(index >= 0)
    {
        len = solve(file,index);
        file = filesave (file,index);
        return(len);
    }    
    while(numberofchar)
    {   
        temp = malloc(BUFFER_SIZE + 1);
        numberofchar = read(fd,BUFFER_SIZE,BUFFER_SIZE);
        temp[BUFFER_SIZE] = '\0';
        if(cheaknew_line(temp,'\n') == -1)
        {
            file = ft_strjoin (file,temp); 
            continue;
        }
        else
        {
            len = solve(file,index);
            file = filesave (temp,index);
            return(len);
        }
        return('\0');
                   
    }
}





int main()
{
    int fd = open("test", O_WRONLY);
    printf("%s",get_next_line(fd));
}