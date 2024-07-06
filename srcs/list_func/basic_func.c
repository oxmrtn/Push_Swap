/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:52:55 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/06 18:01:43 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_DLIST	*ft_last_node(t_DLIST *node)
{
	t_DLIST	*temp;
	
	temp = node;
	while(temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

t_DLIST	*ft_first_node(t_DLIST *node)
{
	t_DLIST	*temp;
	
	temp = node;
	while(temp->prev)
	{
		temp = temp->prev;
	}
	return (temp);
}

void	ft_add_back_dl(t_DLIST **list, int content)
{
	t_DLIST	*new_elem;
	t_DLIST	*last;

	new_elem = malloc(sizeof(t_DLIST));
	if (!new_elem)
		return ;
	new_elem->content = content;
	if (!(*list))
	{
		*list = new_elem;
		new_elem->prev = NULL;
		new_elem->next = NULL;
	}
	else
	{
		last = ft_last_node(*list);
		last->next = new_elem;
		new_elem->prev = last;
		new_elem->next = NULL;
	}
}

void	ft_insert_node(t_DLIST *node, t_DLIST *dest)
{
	t_DLIST	*temp;
	
	if (!dest)
	{
		dest = node;
	}
	temp = ft_last_node(dest);
	temp->next = node;
	node->prev = temp;
	node->next = NULL;
}