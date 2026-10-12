/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralshraw <ralshraw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 09:04:08 by ralshraw          #+#    #+#             */
/*   Updated: 2026/10/12 13:30:08 by ralshraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void d(void *s)
{
    free(s);	
}
// void add_newline(char ch,t_list *head)
// {
// 	t_list *temp;
// 	if(ch!='\n')
// 	{
// 		temp = ft_lstnew('\n');
//         ft_lstadd_back(&head ,temp);
// 	}
// }
t_list *fd_read(int fd)
{
	int		i;
	char	ch[fd][buffer_size];
	t_list *head;
	t_list *temp;

	i = 1;
	ch = '0';
	head = ft_lstnew(ch);
	while(ch !='\n' && i)
    {
        i = read(fd,&ch,1);
		if(i)
        {	
			temp = ft_lstnew(ch);
			if(!temp)
			{
				ft_lstclear(&temp,d);
				return (NULL);
			}
        	ft_lstadd_back(&head ,temp);
		}
    }
	//add_newline(ch,head);
	return (head);
}
char *get_next_line(int fd)
{
    int i;
	char *str;
    t_list *head;
	t_list *temp;
	
	i = 0;
	if(fd == -1)
		return (NULL);
	head = fd_read(fd);
	if (!head)
		return (NULL);
    str = malloc ((ft_lstsize(head) + 1) * sizeof(char));
	if(!str)
		return (NULL);
	temp = head;
	head = head -> next;
    while(head)
    { 
        str[i++] = head -> content;
        head =  head -> next;
    }
    ft_lstclear(&temp,d);
    str[i]='\0';
    return(str);
}


int main()
{

    int i = 0;
    int fd1 = open("foo.txt", O_RDONLY);
    char *str = get_next_line(fd1);
	char *str = get_next_line(fd1);
	printf("%s",str);
	printf("hi im raghad");
    // while(str[i]!='\n')
    // {
    //     printf("%c",str[i]);
    //     i++;
    // }
	close(fd1);
	free(str);

}