/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:08:58 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/17 18:42:24 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

//Find the index of the node we need to insert
int find_place(t_DLIST *stack, t_DLIST *node)
{
    int     i;
    t_DLIST *cur;
    t_DLIST *cur_n;
    
    cur = ft_last_node(stack);
    cur_n = cur->prev;
    i = 0;
    if (node->content > cur->content && what_min(stack) == stack->content)
    {
        i = 0;
        ft_printf("COND 1\n");
    }
    else if (node->content > what_max(stack))
    {
        i = find_max(stack);
        ft_printf("CA PASSSE ICCI%d\n", i);
    }
    else if (node->content < what_min(stack))
    {
        i = find_min(stack);
        ft_printf("laaaaa\n");
    }
    else
    {
        while ((cur && cur_n) && (cur->content > node->content || cur_n->content < node->content))
        {
            cur = cur_n;
            cur_n = cur_n->prev;
            i++;
        }
    }
    return (i);
}

//Give the number of rotation we have to do to get to an index
int index_to_moov(t_DLIST *stack, t_DLIST *node)
{
    int len;
    int i;
    int result;

    i = 0;
    result = 0;
    len = len_stack(stack);
    i = find_place(stack, node);
    if (i > len / 2)
        result = i - len;
    else 
        result = i;
    printf("result = %d\n", i);
    return (result);
}

int bring_it_to_top(t_DLIST *stack, t_DLIST *node)
{
    t_DLIST *temp;
    int     i;
    int     len;
    int     result;

    result = 0;
    len = len_stack(stack);
    i = 0;
    temp = ft_last_node(stack);
    while (temp && (temp != node))
    {
        temp = temp->prev;
        i++;
    }
    if (i > len / 2)
        result = i - len;
    else 
        result = i;
    return (result);
}