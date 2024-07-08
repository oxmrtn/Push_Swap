/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:45:43 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/08 16:05:24 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*buffer;
	
	i = 1;
	buffer = NULL;
	if(argc == 1)
		return(ft_printf("Function require arguments"), 1);
	while (argv[i])
	{
		buffer = ft_strjoin(buffer, argv[i]);
		buffer = ft_strjoin(buffer, " ");
		i++;
	}
	printf("checker %d\n", ft_checker(buffer));
	if (ft_checker(buffer))
		return (ft_printf("Invalid input"), free(buffer), 1);
	t_DLIST *stack = create_list(buffer);
	t_DLIST *stackB = NULL;
	print_lsit(stack);
	ft_printf("----------ROTATE-A-----------\n");
	ft_rotate(&stack);
	ft_rotate(&stackB);
	ft_printf("A = ");
	print_lsit(stack);
	ft_printf("B = ");
	print_lsit(stackB);
	ft_printf("----------RROTATE-A----------\n");
	ft_reverse_rotate(&stack);
	ft_printf("A = ");
	print_lsit(stack);
	ft_printf("B = ");
	print_lsit(stackB);
	ft_printf("------------SWAP-A----------\n");
	ft_swap_a_b(&stack);
	ft_printf("A = ");
	print_lsit(stack);
	ft_printf("B = ");
	print_lsit(stackB);
	ft_printf("------------PUSH-A->B-------\n");
	ft_push(&stack, &stackB);
	ft_printf("A = ");
	print_lsit(stack);
	ft_printf("B = ");
	print_lsit(stackB);
	ft_printf("------------PUSH------------\n");
	ft_push(&stack, &stackB);
	ft_printf("A = ");
	print_lsit(stack);
	ft_printf("B = ");
	print_lsit(stackB);
	ft_printf("------------PUSH------------\n");
	ft_push(&stack, &stackB);
	ft_printf("A =");
	print_lsit(stack);
	ft_printf("B =");
	print_lsit(stackB);
	ft_printf("------------PUSH-B>A---------\n");
	ft_push(&stackB, &stack);
	ft_printf("A = ");
	print_lsit(stack);
	ft_printf("B = ");
	print_lsit(stackB);
	ft_free_chain(stack);
	ft_free_chain(stackB);
}