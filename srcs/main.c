/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:45:43 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/23 16:47:31 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	init(char *buffer)
{
	t_DLIST	*stack_a;
	t_DLIST	*stack_b;

	stack_a = create_list(buffer);
	stack_b = NULL;
	ft_push(&stack_a, &stack_b);
	ft_push(&stack_a, &stack_b);
	ft_printf("pb\npb\n");
	if (stack_b->content > stack_b->next->content)
	{
		ft_swap_a_b(&stack_b);
		ft_printf("sb\n");
	}
	while (len_stack(stack_a) != 0)
	{
		find_best_moov(&stack_a, &stack_b);
	}
	in_order(&stack_b);
	while (stack_b)
	{
		ft_push(&stack_b, &stack_a);
		ft_printf("pa\n");
	}
	ft_free_chain(stack_a);
	ft_free_chain(stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*buffer;

	i = 1;
	buffer = NULL;
	if (argc == 1)
		return (ft_putstr_fd("Error\nPush Swap need argument", 2), 1);
	if (no_duplicate(argv))
		return (ft_putstr_fd("Error\nDuplicate argument", 2), 1);
	while (argv[i])
	{
		buffer = ft_strjoin(buffer, argv[i]);
		buffer = ft_strjoin(buffer, " ");
		i++;
	}
	if (ft_checker(buffer))
		return (ft_putstr_fd("Error\nInvalid argument", 2), free(buffer), 1);
	init (buffer);
	return (1);
}
