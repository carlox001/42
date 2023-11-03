/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:04:21 by czerini           #+#    #+#             */
/*   Updated: 2023/10/22 12:04:28 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}
/*
void	ft_print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*list;
	t_list	*node1;
	t_list	*current;
	t_list	*temp;

	list = NULL;
	node1 = (t_list *)malloc(sizeof(t_list));
	node1->content = "Ciao come stai?";
	node1->next = NULL;
	ft_lstadd_back(&list, node1);
	current = list;
	while (current != NULL)
	{
		ft_print_content(current->content);
		current = current->next;
	}
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (0);
}*/
