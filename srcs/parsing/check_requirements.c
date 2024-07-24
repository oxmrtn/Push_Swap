/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_requirements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:37:59 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/24 17:07:16 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	no_duplicate(char **buffer)
{
	int	i;
	int	j;

	i = 1;
	while (buffer[i])
	{
		j = i + 1;
		while (buffer[j])
		{
			if (ft_strncmp(buffer[i], buffer[j], ft_strlen(buffer[i]) + 1) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// This function check if the list only contains int
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

t_DLIST	*create_list_extends(char **buffer, char *str)
{
	ft_putstr_fd("Error\nAt least one argument is not a int", 2);
	free_tab(buffer);
	free(str);
	return (NULL);
}

t_DLIST	*create_list(char *str)
{
	char	**buffer;
	int		i;
	long	temp;
	t_DLIST	*list;

	list = NULL;
	temp = 0;
	i = 0;
	buffer = ft_split(str, ' ');
	if (!buffer)
		return (NULL);
	while (buffer[i + 1])
		i++;
	while (i >= 0)
	{
		temp = ft_atoi(buffer[i]);
		if (is_int(temp))
			return (create_list_extends(buffer, str));
		ft_add_back_dl(&list, temp);
		free(buffer[i]);
		i--;
	}
	free(buffer);
	free(str);
	return (list);
}

void	print_lsit(t_DLIST *head)
{
	t_DLIST	*node;

	node = ft_last_node(head);
	if (!node)
	{
		ft_printf("\n");
		return ;
	}
	while (node)
	{
		ft_printf("|%d|\n", node->content);
		node = node->prev;
	}
	ft_printf("\n");
}
