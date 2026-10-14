










#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>




#define BUFFER_SIZE 1000
size_t ft_strlen(const char *s)
{
	size_t	i;
	i = 0;
	if(!s)
	return 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
int ft_strchr(const char *s)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	if(!str)
		return -1;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
char	*copy(char *copy , int index)
{
	char *str;
	int i;

	i = 0;
	str = malloc (index + 2);
	while (copy[i]!='\n' && copy[i])
	{
		str[i] = copy[i];
		i++; 
	}
	str[i] = '\n';
    i++;
	str[i] = '\0';
	return (str);
}
char *newfile(char *file,int index)
{
	int i;
	int len;
	char *str;
	
	i = 0;
	index++;
	len = ft_strlen(file);
	str =  malloc(len - index + 1);
    if(!str)
        return NULL;
	while(file[index])
	{
		str[i] = file[index];
		i++;
		index++;
	}
	free(file);
    str[i] = '\0';
	return(str);

}
char	*ft_strjoin(char  *s1, char *s2)
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
    free(s1);
	return (str);
}
char	*ft_strdup(const char *s)
{
	int		lens;
	int		i;
	char	*dis;

	i = 0;
	lens = ft_strlen(s);
	dis = malloc((lens + 1) * sizeof(char));
	if (dis == NULL)
		return (NULL);
	while (lens > i)
	{
		dis[i] = s[i];
		i++;
	}
	dis[i] = '\0';
	return (dis);
}

char	*get_next_line(int fd)
{
    static char *file;
	char *line;
	char *temp;
	int i = 0;
	int flag = 0;
	int x;
    if(fd<0 || BUFFER_SIZE <=0)
        return(NULL);
    if(!file)
    file = ft_strdup("");
	if(file)
	{
		//printf("00");
		if (ft_strchr(file) >= 0)
		{
			line = copy(file, ft_strchr(file));
			file = newfile(file,ft_strchr(file));
			return(line);
		}
	}
    x = 1;
	while(ft_strchr(file) == -1 && x > 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
        if(!temp)
        {
            free (file);
            file = NULL;
            return(file);
        }
		x = read(fd, temp, BUFFER_SIZE);
		if(x==-1)
        {
            free(temp);
            free(file);
            file = NULL;
            return(NULL);
        }
		temp[x] = '\0';
		if (ft_strchr(temp) >= 0)
		{
            file = ft_strjoin(file ,temp);
			line = copy(file, ft_strchr(file));
			file = newfile(file,ft_strchr(file));
             free(temp);
			return line;
		}
        else
        {
             file = ft_strjoin(file ,temp);
             free(temp);
            //file = newfile(file,ft_strchr(file));
        }
	}
    if (file && file[0])
	{
		line = ft_strdup(file);
		free(file);
		file = NULL;
		return (line);
	}
	free(file);
	file = NULL;
	return (NULL);
}
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("raghad", O_RDONLY);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
     printf("%s", str);
    free(str);
    str = get_next_line(fd);
     printf("%s", str);
    free(str);
    str = get_next_line(fd);
     printf("%s", str);
    free(str);
    str = get_next_line(fd);
     printf("%s", str);
    free(str);
    str = get_next_line(fd);
     printf("%s", str);
    free(str);
        str = get_next_line(fd);
     printf("%s", str);
    free(str);
    close(fd);
	return (0);
}