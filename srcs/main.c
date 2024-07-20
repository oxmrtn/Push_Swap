/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:45:43 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/21 00:06:52 by mtrullar         ###   ########.fr       */
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
	if (ft_checker(buffer))
		return (ft_printf("Invalid input"), free(buffer), 1);
	t_DLIST *stack = create_list(buffer);
	t_DLIST *stackB = NULL;
	ft_printf("---------STACK A--------\n\n");
	print_lsit(stack);
	ft_printf("------------------------\n\n");
	//sort_5(&stack, &stackB);
	//sort_3(&stack);
	ft_push(&stack, &stackB);
	ft_push(&stack, &stackB);
	if (stackB->content > stackB->next->content)
		ft_swap_a_b(&stackB);
	ft_printf("---------STACK A--------\n\n");
	print_lsit(stack);
	ft_printf("------------------------\n\n");
	ft_printf("---------STACK B--------\n\n");
	print_lsit(stackB);
	ft_printf("------------------------\n\n");
	// ft_printf("MOOV =--|%d|--\n\n", moov->nmoov);
	// ft_printf("MOOV TO DO= --|%s|--\n\n", moov->buffer);
	// ft_printf("avant rotate\n");
	// print_lsit(stack);
	// print_lsit(stackB);
	// ft_rr(stack, stackB);
	// ft_printf("apres premiere rotate\n");
	// print_lsit(stack);
	// print_lsit(stackB);
	// ft_rr(stack, stackB);
	// ft_printf("apres deuxieme rotate\n");
	// ft_push(&stack, &stackB);
	// print_lsit(stack);
	// print_lsit(stackB);
	while (len_stack(stack) != 3)
	{
		find_best_moov(&stack, &stackB);
	}
	in_order(&stackB);
	//sort_3(&stack);
	//end_sort(&stack, &stackB);
	ft_printf("---------STACK A--------\n\n");
	print_lsit(stack);
	ft_printf("------------------------\n\n");
	ft_printf("---------STACK B--------\n\n");
	print_lsit(stackB);
	ft_printf("------------------------\n\n");
	ft_free_chain(stack);
	ft_free_chain(stackB);
}