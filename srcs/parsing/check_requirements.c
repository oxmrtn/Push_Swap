/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_requirements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:37:59 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/06 18:10:21 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (str[i] == ' ')))
		{
			if (!((str[i] == '+' || str[i] == '-' ) && ft_isdigit(str[i + 1])))
				return (1);
		}
		i++;
	}
	return (0);
}

t_DLIST	*create_list(char *str)
{
	char	**buffer;
	int		i;
	int		temp;
	t_DLIST	*list;

	list = NULL;
	temp = 0;
	i = 0;
	buffer = ft_split(str, ' ');
	if (!buffer)
		return (NULL);
	while (buffer[i])
	{
		temp = ft_atoi(buffer[i]);
		ft_add_back_dl(&list, temp);
		free(buffer[i]);
		i++;
	}
	free(buffer);
	return (list);
}

void	print_lsit(t_DLIST *head)
{
	t_DLIST	*node;

	node = ft_first_node(head);
	if (!node)
	{
		ft_printf("ici");
		return ;
	}
	while (node)
	{
		ft_printf("%d|", node->content);
		node = node->next;
	}
}