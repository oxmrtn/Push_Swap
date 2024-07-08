/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:46:16 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/08 16:00:38 by mtrullar         ###   ########.fr       */
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
t_DLIST	*ft_first_node(t_DLIST *node);
t_DLIST	*create_list(char *str);

int		main(int argc, char **argv);
int		ft_checker(char *str);

void	ft_add_back_dl(t_DLIST **list, int content);
void	print_lsit(t_DLIST *head);
void	ft_insert_node(t_DLIST **node, t_DLIST *dest);
void	ft_swap_a_b(t_DLIST **stack);
void	ft_push(t_DLIST **to_push, t_DLIST **dest);
void	ft_rotate(t_DLIST **stack);
void	ft_reverse_rotate(t_DLIST **stack);
void	ft_free_chain(t_DLIST *stack);

#endif