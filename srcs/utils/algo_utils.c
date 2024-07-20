/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:08:58 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/21 00:32:02 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int from_bottom(t_DLIST *stack, int value)
{
    t_DLIST *node;
    int     i;

    i = 0;
    node = stack;
    while (node && node->content < value)
    {
        node = node->next;
        i++;
    }
    return (i);
}

int from_top(t_DLIST *stack, int value)
{
    t_DLIST *node;
    int     i;

    i = 0;
    node = ft_last_node(stack);
    while (node && node->content > value)
    {
        node = node->prev;
        i++;
    }
    return (i);
}

//Find the index of the node we need to insert
int find_place(t_DLIST *stack, t_DLIST *node)
{
    int     i;
    // t_DLIST *cur;
    // //t_DLIST *cur_n;

    // cur = ft_last_node(stack);
    // cur_n = cur->prev;
    i = 0;
    //CAS PARFAIT
    
    if (from_bottom(stack, node->content) >= from_top(stack, node->content))
        i = from_top(stack, node->content);
    else
        i = len_stack(stack) - from_bottom(stack, node->content);
    // if (node->content > cur->content && what_min(stack) == stack->content)
    //     i = 0;
    // else if (node->content > what_max(stack))
    //     i = find_max(stack);
    // else if (node->content < what_min(stack))
    //     i = find_min(stack);
    // else
    // {
    //     while ((cur && cur_n) && (cur->content > node->content || cur_n->content < node->content))
    //     {
    //         cur = cur_n;
    //         cur_n = cur_n->prev;
    //         i++;
    //     }
    // }
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
    ft_printf("result = %d\n", i);
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
