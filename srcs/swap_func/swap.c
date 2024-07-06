/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:20:07 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/06 18:10:42 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_swap_a_b(t_DLIST *stack)
{
	t_DLIST	*temp;
	t_DLIST	*prev;
	
	temp = ft_last_node(stack);
	if (temp == stack || !stack)
		return ;
	prev = temp->prev;
	temp->next = prev;
	temp->prev = prev->prev;
	prev->prev = temp;
	prev->next = NULL;
}

void	ft_push(t_DLIST *to_push, t_DLIST *dest)
{
	t_DLIST	*last;
	
	if (!to_push)
		return ;
	last = ft_last_node(to_push);
	last->prev->next = NULL;
	ft_insert_node(last, dest);
}

void	ft_rotate(t_DLIST **stack)
{
	t_DLIST	*last;
	t_DLIST	*first;

	last = ft_last_node(*stack);
	first = ft_first_node(*stack);
	first->prev = last;
	last->prev->next = NULL;
	last->next = first;
	*stack = last;
}

void	ft_reverse_rotate(t_DLIST *stack)
{
	t_DLIST	*last;
	t_DLIST	*first;

	last = ft_last_node(stack);
	first = ft_first_node(stack);
	last->next = first;
	first->prev = last;
	first->next->prev = NULL;
	first->next = NULL;
}