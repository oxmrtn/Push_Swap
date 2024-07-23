/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mooves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:48:44 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/23 14:22:16 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

//Merge into a buffer the moov to do
void	moov_to_do(int count, int count_dest, t_MOOV *moov)
{
	char	*buffer;

	buffer = NULL;
	while (count != 0 || count_dest != 0)
	{
		if (count < 0 && count_dest < 0)
		{
			buffer = ft_strjoin(buffer, " revt");
			count++;
			count_dest++;
		}
		else if (count > 0 && count_dest > 0)
		{
			buffer = ft_strjoin(buffer, " rr");
			count--;
			count_dest--;
		}
		else
		{
			if (count > 0)
			{
				buffer = ft_strjoin(buffer, " ra");
				count--;
			}
			else if (count < 0)
			{
				buffer = ft_strjoin(buffer, " reva");
				count++;
			}
			if (count_dest > 0)
			{
				buffer = ft_strjoin(buffer, " rb");
				count_dest--;
			}
			else if (count_dest < 0)
			{
				buffer = ft_strjoin(buffer, " revb");
				count_dest++;
			}
		}
	}
	buffer = ft_strjoin(buffer, " pb");
	moov->buffer = buffer;
	
}

//Return a struct containing a buffer with moove
//to do and number of moov to moov a certain element
t_MOOV	*hr_moov(int count, int count_dest)
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

//Meta func that contains every func
t_MOOV	*calc_moov(t_DLIST *node, t_DLIST *origin, t_DLIST *dest)
{
	int			count;
	int			count_dest;

	count = 0;
	count_dest = 0; 
	count = bring_it_to_top(origin, node);
	count_dest = index_to_moov(dest, node);
	ft_printf("NODE = %d, dest = %d, count = %d \n", node->content, count_dest, count);
	return (hr_moov(count, count_dest));
}
