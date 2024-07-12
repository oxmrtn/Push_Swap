/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mooves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:48:44 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/12 14:42:38 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	moov_to_do(int count, int count_dest, t_MOOV *moov)
{
	char	*buffer;

	buffer = NULL;
	while (count != 0 || count_dest != 0)
	{
		if (count < 0 && count_dest < 0)
		{
			buffer = ft_strjoin(buffer, " rro");
			count++;
			count_dest++;
		}
		else if (count > 0 && count_dest > 0)
		{
			buffer = ft_strjoin(buffer, " rrr");
			count--;
			count_dest--;
		}
		else
		{
			if (count > 0)
			{
				buffer = ft_strjoin(buffer, " rra");
				count--;
			}
			else if (count < 0)
			{
				buffer = ft_strjoin(buffer, " ra");
				count++;
			}
			if (count_dest > 0)
			{
				buffer = ft_strjoin(buffer, "rrb");
				count_dest--;
			}
			else if (count_dest < 0)
			{
				buffer = ft_strjoin(buffer, " rb");
				count_dest++;
			}
		}
	}
	buffer = ft_strjoin(buffer, " pb");
	moov->buffer = buffer;
	
}

t_MOOV	*hr_moov(int	count, int count_dest)
{
	t_MOOV	*moov;

	moov = malloc(sizeof(t_MOOV));
	if (!moov)
		return (NULL);
	moov_to_do(count, count_dest, moov);
	if (count <= 0 && count_dest <= 0)
	{
		if (count < count_dest)
			return (moov->nmoov = (-1 * count) + 1, moov);
		else
			return (moov->nmoov = (-1 * count_dest) + 1, moov);
	}
	else if (count >= 0 && count_dest >= 0)
	{
		if (count > count_dest)
			return (moov->nmoov = count + 1, moov);
		else
			return (moov->nmoov = count_dest + 1, moov);
	}
	else
	{
		if (count < 0)
			return (moov->nmoov = (-1 * count) + count_dest, moov);
		else
			return (moov->nmoov = count + (-1 * count_dest), moov);
	}
}

int	find_place(t_DLIST *node, t_DLIST *dest)
{
	t_DLIST	*temp;
	int		i;
	int		count;
	const int	med = len_stack(dest);
	
	temp = ft_last_node(dest);
	i = 0;
	while(temp && (node->content < temp->content))
	{
		temp = temp->prev;
		i++;
	}
	if (i == 0)
		count = 0;
	else if (i == (med))
		count = -1;
	else if (i > (med) / 2)
		count = -(i);
	else
		count = med - (i + 1);
	return (count);
}

t_MOOV	*calc_moov(t_DLIST *node, t_DLIST *origin, t_DLIST *dest)
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
