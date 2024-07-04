/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:46:16 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/04 16:02:44 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/incs/ft_printf.h"

typedef struct t_DLIST
{
	int		content;
	t_DLIST	*prev;
	t_DLIST	*next;
}				t_DLIST;

t_DLIST	*ft_last_node(t_DLIST *node);
t_DLIST	*create_list(char *str);

int	ft_checker(char *str);

void	ft_add_back_dl(t_DLIST *list, int content);

#endif