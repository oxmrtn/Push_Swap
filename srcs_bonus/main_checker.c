/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:07:04 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/27 01:35:45 by mtrullar         ###   ########.fr       */
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
	if (!moov)
	{
		if (is_sorted(stack_a, stack_b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_free_chain(stack_a);
		ft_free_chain(stack_b);
		return ;
	}
	execute_check_moov(moov, &stack_a, &stack_b);
	free(moov);
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
		return (ft_putstr_fd("Error\n", 2), 0);
	while (argv[i])
	{
		buf = ft_strjoin(buf, argv[i++]);
		buf = ft_strjoin(buf, " ");
	}
	if (ft_checker(buf))
		return (ft_putstr_fd("Error\n", 2), free(buf), 0);
	buffer = NULL;
	temp = get_next_line(0);
	while (temp)
	{
		buffer = ft_strjoin(buffer, temp);
		free(temp);
		temp = get_next_line(0);
	}
	init_checker(buffer, &buf);
}
