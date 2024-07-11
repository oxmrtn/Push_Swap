/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:45:43 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/11 15:25:34 by mtrullar         ###   ########.fr       */
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
	//sort_5(&stack, &stackB);
	//sort_3(&stack);
	ft_push(&stack, &stackB);
	ft_push(&stack, &stackB);
	ft_push(&stack, &stackB);
	ft_push(&stack, &stackB);
	t_DLIST *node = ft_last_node(stack)->prev->prev;
	ft_printf("--|%d|--\n\n", node->content);
	t_MOOV	*moov = calc_moov(node, stack, stackB);
	ft_printf("MOOV =--|%d|--\n\n", moov->nmoov);
	ft_printf("MOOV TO DO= --|%s|--\n\n", moov->buffer);
	ft_printf("avant rotate\n");
	print_lsit(stack);
	print_lsit(stackB);
	ft_rr(stack, stackB);
	ft_printf("apres premiere rotate\n");
	print_lsit(stack);
	print_lsit(stackB);
	ft_rr(stack, stackB);
	ft_printf("apres deuxieme rotate\n");
	//ft_push(&stack, &stackB);
	print_lsit(stack);
	print_lsit(stackB);
	ft_free_chain(stack);
	ft_free_chain(stackB);
	free(moov->buffer);
	free(moov);
}