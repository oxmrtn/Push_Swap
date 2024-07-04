/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:45:43 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/04 15:37:31 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*buffer;
	
	i = 1;
	if(argc == 1)
		return(ft_printf("Function require arguments"), 1);
	while (argv[i])
	{
		buffer = ft_strjoin(buffer, argv[i]);
		i++;
	}
}