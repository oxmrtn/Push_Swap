/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:07:04 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/24 17:18:46 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_DLIST	*create_list_checker_extend(char **buffer)
{
	ft_putstr_fd("Error\n", 2);
	free_tab(buffer);
	return (NULL);
}

t_DLIST	*create_list_checker(char *str)
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
			return (create_list_checker_extend(buffer));
		ft_add_back_dl(&list, temp);
		free(buffer[i]);
		i--;
	}
	free(buffer);
	free(str);
	return (list);
}

int	is_sorted(t_DLIST *stack)
{
	t_DLIST	*node;

	if (!stack || !stack->next)
		return (0);
	node = stack->next;
	while (node)
	{
		if (stack->content < node->content)
			return (0);
		stack = node;
		node = node->next;
	}
	return (1);
}

void	init_checker(char *moov, char **args)
{
	t_DLIST	*stack_a;
	t_DLIST	*stack_b;

	stack_a = create_list_checker(*args);
	if (!stack_a)
	{
		free(*args);
		return ;
	}
	stack_b = NULL;
	execute_check_moov(moov, &stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	char	*buffer;
	char	*buf;
	char	*temp;
	int		i;

	i = 1;
	buf = NULL;
	if (argc < 2)
		return (ft_putstr_fd("Error", 2), 1);
	while (argv[i])
	{
		buf = ft_strjoin(buf, argv[i]);
		buf = ft_strjoin(buf, " ");
		i++;
	}
	buffer = NULL;
	temp = get_next_line(0);
	while (temp)
	{
		buffer = ft_strjoin(buffer, temp);
		free(temp);
		temp = get_next_line(0);
	}
	init_checker(buffer, &buf);
	free(buffer);
}
