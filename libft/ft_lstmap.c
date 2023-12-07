/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:15:10 by czerini           #+#    #+#             */
/*   Updated: 2023/10/22 13:15:17 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*map_content;
	t_list	*new_node;

	new_lst = NULL;
	if (f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)//fino alla fine della lista og
	{
		map_content = (*f)(lst->content); //salvo il contenuto a cui è stata applicata la funzione f senza cambiare quello og
		new_node = (t_list *)malloc(sizeof(t_list)); //creo nuovo nodo
		if (new_node == NULL) //se l'allocazione fallisce
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_node->content = map_content; //salvo il contenuto  nel nuovo nodo
		new_node->next = NULL;
		ft_lstadd_back(&new_lst, new_node); //aggiungo un nuovo nodo alla fine
		lst = lst->next; //va avanti con la lista og
	}
	return (new_lst);
}
