/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:11:49 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/12 15:18:24 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void    end_sort(t_DLIST **stackA, t_DLIST **stackB)
{
    t_DLIST *top_A;
    t_DLIST *top_B;
    
    while (len_stack(stackB) != 0)
    {
        top_B = ft_last_node(*stackB);
        top_A = ft_last_node(*stackA);
        if ()
    }
}