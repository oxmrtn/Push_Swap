/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mooves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:48:44 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/10 16:40:32 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"
int	hr_moov(int	count, int count_dest)
{
	if (count <= 0 && count_dest <= 0)
	{
		if (count < count_dest)
			return ((-1 * count) + 1);
		else
			return ((-1 * count_dest) + 1);
	}
	else if (count >= 0 && count_dest >= 0)
	{
		if (count > count_dest)
			return (count + 1);
		else
			return (count_dest + 1);
	}
	else
	{
		if (count < 0)
			return ((-1 * count) + count_dest);
		else
			return (count + (-1 * count_dest));
	}
}
int	find_place(t_DLIST *node, t_DLIST *dest)
{
	t_DLIST	*temp;
	int		i;
	int		count;
	const int	med = len_stack(dest);
	
	temp = dest;
	i = 0;
	while(temp && (node->content < temp->content))
	{
		temp = temp->next;
		i++;
	}
	if (i == 0)
		count = -1;
	else if (i == (med))
		count = 0;
	else if (i > (med) / 2)
		count = med - (i + 1);
	else
		count = -(i);
	return (count);
}

int	calc_moov(t_DLIST *node, t_DLIST *origin, t_DLIST *dest)
{
	int			count;
	int			count_dest;
	int			i;
	const int	med = len_stack(origin);
	t_DLIST		*tmp;

	tmp = origin;
	i = 0;
	count = 0;
	count_dest = 0;
	while (tmp != node)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == 0)
		count = -1;
	else if (i == (med - 1))
		count = 0;
	else if (i >= (med) / 2)
		count = -(med - (i + 1));
	else
		count = (i + 1);
	count_dest = find_place(node, dest);
	return (hr_moov(count, count_dest));
}
