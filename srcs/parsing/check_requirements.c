/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_requirements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:37:59 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/04 16:04:21 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_checker(char *str)
{
	while (*str)
	{
		if (!is_digit(*str) || !*str == ' ')
			return (1);
		str++;
	}
	return (0);
}

t_DLIST	*create_list(char *str)
{
	char	**buffer;
	int		i;
	int		temp;
	t_DLIST	*list;

	temp = 0;
	i = 0;
	buffer = ft_split(str, " ");
	if (!buffer)
		return (1);
	while (buffer[i])
	{
		temp = ft_atoi(buffer[i]);
		ft_add_back_dl(list, temp);
		free(buffer[i]);
		i++;
	}
	free(buffer);
	return (list);
}