/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:19:34 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/09 16:45:46 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_sorted(t_DLIST *stack)
{
	int		tmp;
	t_DLIST	*tempo;

	if (!stack)
		return (1);
	tmp = stack->content;
	tempo = stack->next;
	while (tempo)
	{
		if (tmp < tempo->content)
			return (0);
		tmp = tempo->content;
		tempo = tempo->next;
	}
	return (1);
}

void	sort_3(t_DLIST **stackA)
{
	t_DLIST	*temp;

	while(!ft_sorted(*stackA))
	{
		temp = ft_last_node(*stackA);
		if (temp->content > temp->prev->content)
		{
			ft_swap_a_b(stackA);
			ft_printf("sa\n");
		}
		else
		{
			ft_reverse_rotate(stackA);
			ft_printf("rra\n");
		}
	}
}

