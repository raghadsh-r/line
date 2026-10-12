/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralshraw <ralshraw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:00:18 by ralshraw          #+#    #+#             */
/*   Updated: 2026/10/12 12:20:32 by ralshraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char content)
{
	t_list	*point;

	point = malloc (sizeof(t_list));
	if (!point)
		return (NULL);
	point -> content = content;
	point -> next = NULL ;
	return (point);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next)
	{
		temp = temp -> next;
	}
	temp -> next = new;
}

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count;
	t_list			*str;

	count = 0;
	str = lst;
	if (!lst)
		return (0);
	while (str)
	{
		str = str -> next;
		count++;
	}
	return (count);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*s;

	// if (!*lst)
	// 	return ;
	if(!del)
		return;
	if(!lst)
		return;
	temp = *lst;
	while (temp)
	{
		s = temp -> next;
		ft_lstdelone(temp, del);
		temp = s;
	}
	*lst = NULL;
}
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	free(lst);
}


