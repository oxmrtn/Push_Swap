/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:19:34 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/09 16:03:27 by mtrullar         ###   ########.fr       */
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

void	sort_5(t_DLIST **stackA, t_DLIST **stackB)
{
	int	count;

	count = 0;
	ft_push(stackA, stackB);
	ft_printf("pa\n");
	ft_push(stackA, stackB);
	ft_printf("pa\n");
	sort_3(stackA);
	ft_printf("stack A = \n");
	print_lsit(*stackA);
	if ((*stackB)->content > (*stackB)->next->content)
	{
		ft_swap_a_b(stackB);
		ft_printf("sb\n");
	}
	ft_printf("stack B = \n");
	print_lsit(*stackB);
	while (*stackB)
	{
		if ((ft_last_node(*stackA)->content) > (ft_last_node(*stackB)->content))
		{
			ft_push(stackB,stackA);
			ft_printf("pb\n");
		}
		else if ((*stackA)->content < (ft_last_node(*stackB)->content))
		{ 
			ft_push(stackB, stackA);
			ft_rotate(stackA);
			ft_printf("pb\nrra\n");
		}
		else
		{
			ft_reverse_rotate(stackA);
			count++;
			ft_printf("rra\ncount = %d\n", count);

		}
		ft_printf("Stack A = \n");
		print_lsit(*stackA);
		ft_printf("Stack B = \n");
		print_lsit(*stackB);
	}
	while(count >= 0)
	{
		ft_rotate(stackA);
		ft_printf("ra\n");
		count--;
	}
}
