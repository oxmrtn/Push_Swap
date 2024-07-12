/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:11:49 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/13 00:38:02 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void    make_it_right(t_DLIST **stack, int i)
{
    while (i != 0)
    {
        if (i < 0)
        {
            ft_rotate(stack);
            ft_printf("ra\n");
            i++;
        }
        else
        {
            ft_reverse_rotate(stack);
            ft_printf("rra\n");
            i--;
        }
    }
}

void    make_it_sort(t_DLIST **stack)
{
    int i;

    i = find_min(*stack);
    make_it_right(stack, i);
}

void    find_place(t_DLIST **stack, t_DLIST *top)
{
    t_DLIST *temp;
    int     i;

    i = 0;
    temp = ft_last_node(*stack);
    while(temp->content < top->content)
    {
        temp = temp->prev;
        i++;
    }
    if (i > len_stack(*stack) / 2)
        i = i - len_stack(*stack);
    make_it_right(stack, i);
}

void    end_sort(t_DLIST **stackA, t_DLIST **stackB)
{
    t_DLIST *top_B;
    
    while (len_stack(*stackB) != 0)
    {
        top_B = ft_last_node(*stackB);
        find_place(stackA , top_B);
        ft_push(stackB, stackA);
        ft_printf("pb\n");
    }
    make_it_sort(stackA);
}