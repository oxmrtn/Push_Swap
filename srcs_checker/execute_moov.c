/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:23:33 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/23 17:26:02 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	execute_check_bis(char **moov, int *i, t_DLIST **sA, t_DLIST **sB)
{
	if (!ft_strncmp(moov[*i], "pb", ft_strlen(moov[*i])))
		ft_push(sA, sB);
	else if (!ft_strncmp(moov[*i], "pa", ft_strlen(moov[*i])))
		ft_push(sB, sA);
	else if (!ft_strncmp(moov[*i], "rr", ft_strlen(moov[*i])))
		ft_rr(sA, sB);
	else if (!ft_strncmp(moov[*i], "rrr", ft_strlen(moov[*i])))
		ft_rrr(sA, sB);
	else if (!ft_strncmp(moov[*i], "ra", ft_strlen(moov[*i])))
		ft_rotate(sA);
	else if (!ft_strncmp(moov[*i], "rra", ft_strlen(moov[*i])))
		ft_reverse_rotate(sA);
	else if (!ft_strncmp(moov[*i], "rb", ft_strlen(moov[*i])))
		ft_rotate(sB);
	else if (!ft_strncmp(moov[*i], "rrb", ft_strlen(moov[*i])))
		ft_reverse_rotate(sB);
	ft_printf("%s\n", moov[*i]);
	free(moov[*i]);
	(*i)++;
}

//This function execute the list of moov in str
void	execute_check_moov(char *str, t_DLIST **stackA, t_DLIST **stackB)
{
	char	**moov;
	int		i;

	i = 0;
	moov = ft_split(str, '\n');
	if (!moov)
		return ;
	while (moov[i])
	{
		execute_moov_bis(moov, &i, stackA, stackB);
	}
	free(moov);
}