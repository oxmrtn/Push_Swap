/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:46:16 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/05 15:42:51 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/incs/ft_printf.h"

typedef struct t_DLIST
{
	int		content;
	struct t_DLIST	*prev;
	struct t_DLIST	*next;
}				t_DLIST;

t_DLIST	*ft_last_node(t_DLIST *node);
t_DLIST	*create_list(char *str);

int		main(int argc, char **argv);
int		ft_checker(char *str);

void	ft_add_back_dl(t_DLIST *list, int content);
void	print_lsit(t_DLIST *head);

#endif