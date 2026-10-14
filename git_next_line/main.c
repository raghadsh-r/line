










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
	str = malloc (index + 1);
	while (copy[i]!='\n')
	{
		str[i] = copy[i];
		i++; 
	}
	str[i] = '\n';
	str[++i] = '\0';
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
	while(file[index])
	{
		str[i] = file[index];
		i++;
		index++;
	}
	free(file);
	return(str);

}
char	*ft_strjoin(char  *s1, char  *s2)
{
	size_t	lens2;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lens2 = ft_strlen(s2);
	while(s2[j]!='\n')
	{
		j++;
	}
	j++;
	str = malloc((ft_strlen(s1) + lens2 - i + 1) * sizeof(char));
	if(s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}
char	*get_next_line(int fd)
{
    static char *file;
	char *line;
	char *temp;
	int i = 0;
	int flag = 0;
	int x;
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
	while(ft_strchr(file) >= 0 || x > 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
		x = read(fd, temp, BUFFER_SIZE);
		//printf("020");
		temp[BUFFER_SIZE] = '\0';
		if (ft_strchr(temp) >= 0)
		{
			line = copy(temp, ft_strchr(temp));
			file = ft_strjoin(file ,temp);
			//printf("000");
			return line;
		}
	}
	free(file);
	free(line);
	free(temp);
	return (NULL);
}
int main()
{
	int x;
	char *file;
     int fd = open("test", O_RDONLY);
 	//fd = -1;
	char *str;
	str=get_next_line(fd);
	printf("%s",str);
	free(str);
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
	free(file);
}