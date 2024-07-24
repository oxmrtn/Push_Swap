/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:46:12 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/24 17:11:53 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

// Return len of a stack
int	len_stack(t_DLIST *node)
{
	t_DLIST	*temp;
	int		i;

	i = 1;
	if (!node)
		return (0);
	temp = node;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

// Free a char**
void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// Return 1 if nbr is not a int
int	is_int(long nbr)
{
	return (nbr > 2147483647 || nbr < -2147483648);
}
