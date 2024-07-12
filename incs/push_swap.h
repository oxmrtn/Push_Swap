/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:46:16 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/12 15:01:07 by mtrullar         ###   ########.fr       */
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

typedef struct t_MOOV
{
	char	*buffer;
	int		nmoov;
	t_DLIST	*node;
}			t_MOOV;

t_DLIST	*ft_last_node(t_DLIST *node);
t_DLIST	*ft_first_node(t_DLIST *node);
t_DLIST	*create_list(char *str);

int		main(int argc, char **argv);
int		ft_checker(char *str);
int		len_stack(t_DLIST *node);
t_MOOV	*calc_moov(t_DLIST *node, t_DLIST *origin, t_DLIST *dest);

void    in_order(t_DLIST **stack);
void    find_best_moov(t_DLIST **stackA, t_DLIST **stacKB);
void	ft_add_back_dl(t_DLIST **list, int content);
void	print_lsit(t_DLIST *head);
void	ft_insert_node(t_DLIST **node, t_DLIST *dest);
void	ft_swap_a_b(t_DLIST **stack);
void	ft_push(t_DLIST **to_push, t_DLIST **dest);
void	ft_rotate(t_DLIST **stack);
void	ft_reverse_rotate(t_DLIST **stack);
void	ft_free_chain(t_DLIST *stack);
void	sort_3(t_DLIST **stackA);
void	ft_rrr(t_DLIST *stackA, t_DLIST *stackB);
void	ft_rr(t_DLIST *stackA, t_DLIST *stackB);
void	ft_ss(t_DLIST *stackA, t_DLIST *stackB);

#endif