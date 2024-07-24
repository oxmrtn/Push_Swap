/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:07:04 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/24 16:00:46 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int is_sorted(t_DLIST *stack)
{
    t_DLIST *node;
    
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

	stack_a = create_list(*args);
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
		return (ft_putstr_fd("Error\nNeed an arguments", 2), 1);
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
}
