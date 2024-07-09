/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:45:43 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/09 15:35:58 by mtrullar         ###   ########.fr       */
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
	sort_5(&stack, &stackB);
	//sort_3(&stack);
	print_lsit(stack);
	ft_free_chain(stack);
	ft_free_chain(stackB);
}