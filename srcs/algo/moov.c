/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:41:19 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/13 00:24:23 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int     find_min(t_DLIST *stack)
{
    t_DLIST *temp;
    int     min;
    int     i;
    int     j;
    
    min = 100000;
    i = 1;
    j = 0;
    temp = ft_last_node(stack);
    while (temp)
    {
        if (min > temp->content)
        {
            min = temp->content;
            j = i;
        }
        temp = temp->prev;
        i++;
    }
    return (j);
}

void    in_order(t_DLIST **stack)
{
    int i;

    i = find_min(*stack);
    if (i <= len_stack(*stack) / 2)
    {
        while (i > 0)
        {
            ft_rotate(stack);
            ft_printf("rb\n");
            i--;
        }
    }
    else
    {
        while (i > 0)
        {
            ft_reverse_rotate(stack);
            ft_printf("rrb\n");
            i--;
        }
    }
    
}

void    execute_moov(char *str, t_DLIST **stackA, t_DLIST **stackB)
{
    char    **moov;
    int     i;

    i = 0;
    moov = ft_split(str, ' ');
    if (!moov)
        return ;
    while (moov[i])
    {
        if (!ft_strncmp(moov[i], "pb", ft_strlen(moov[i])))
            ft_push(stackA, stackB);
        else if (!ft_strncmp(moov[i], "pa", ft_strlen(moov[i])))
            ft_push(stackB, stackA);
        else if (!ft_strncmp(moov[i], "rrr", ft_strlen(moov[i])))
            ft_rrr(*stackA, *stackB);
        else if (!ft_strncmp(moov[i], "rro", ft_strlen(moov[i])))
            ft_rr(*stackA, *stackB);
        else if (!ft_strncmp(moov[i], "ra", ft_strlen(moov[i])))
            ft_rotate(stackA);
        else if (!ft_strncmp(moov[i], "rra", ft_strlen(moov[i])))
            ft_reverse_rotate(stackA);
        else if (!ft_strncmp(moov[i], "rb", ft_strlen(moov[i])))
            ft_rotate(stackB);
        else if (!ft_strncmp(moov[i], "rrb", ft_strlen(moov[i])))
            ft_reverse_rotate(stackB);
        ft_printf("%s\n", moov[i]);
        free(moov[i]);
        i++;
    }
    free(moov);
    ft_printf("---------STACK A--------\n\n");
	print_lsit(*stackA);
	ft_printf("------------------------\n\n");
    ft_printf("---------STACK B--------\n\n");
	print_lsit(*stackB);
	ft_printf("------------------------\n\n");
}

void    find_best_moov(t_DLIST **stackA, t_DLIST **stacKB)
{
    int     i;
    t_MOOV  *res;
    t_MOOV  *temp;
    t_DLIST *node;

    res = malloc(sizeof(t_MOOV));
    if (!res)
        return ;
    res->nmoov = 10000;
    i = 1;
    node = ft_last_node(*stackA);
    while (node && i > 0)
    {
        temp = calc_moov(node, *stackA, *stacKB);
        if (temp->nmoov < res->nmoov)
        {
            res->nmoov = temp->nmoov;
            res->buffer = ft_strdup(temp->buffer);
            res->node = node;
            i = res->nmoov;
        }
        i--;
        node = node->next;
        free(temp->buffer);
        free(temp);
    }
    execute_moov(res->buffer, stackA, stacKB);
    free(res->buffer);
    free(res);
}
