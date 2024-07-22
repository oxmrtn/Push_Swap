/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:41:19 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/22 18:44:49 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void    in_order(t_DLIST **stack)
{
    int i;

    i = find_min(*stack);
    if (i < len_stack(*stack) / 2)
    {
        while ((*stack)->content != what_min(*stack))
        {
            ft_rotate(stack);
            ft_printf("rb\n");
            i--;
        }
    }
    else
    {
        while ((*stack)->content != what_min(*stack))
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
        else if (!ft_strncmp(moov[i], "rr", ft_strlen(moov[i])))
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
	ft_printf("_________STACK A__________\n");
	print_lsit(*stackA);
	ft_printf("__________________________\n");
	ft_printf("_________STACK B__________\n");
	print_lsit(*stackB);
	ft_printf("__________________________\n");
}

void    find_best_moov(t_DLIST **stackA, t_DLIST **stacKB)
{
    t_MOOV  *res;
    t_MOOV  *temp;
    t_DLIST *node;

    res = malloc(sizeof(t_MOOV));
    if (!res)
        return ;
    res->nmoov = 2147483647;
    node = ft_last_node(*stackA);
    while (node)
    {
        temp = calc_moov(node, *stackA, *stacKB);
        if (temp->nmoov < res->nmoov)
        {
			ft_printf("NODE = %d , NBR = %d, moovs = %s\n", node->content, temp->nmoov, temp->buffer);
            res->nmoov = temp->nmoov;
			if (res->buffer)
				free(res->buffer);
            res->buffer = ft_strdup(temp->buffer);
        }
        node = node->prev;
        free(temp->buffer);
        free(temp);
    }
	ft_printf("buffer = %s\n", res->buffer);
    execute_moov(res->buffer, stackA, stacKB);
	if (res->buffer)
    	free(res->buffer);
    free(res);
}
