/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:46:12 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/10 15:25:20 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	len_stack(t_DLIST *node)
{
	t_DLIST	*temp;
	int		i;

	i = 1;
	if (!node)
		return (0);
	temp = node;
	while(temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}