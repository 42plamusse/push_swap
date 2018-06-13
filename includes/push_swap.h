/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:44:52 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/13 15:48:12 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "utils.h"
# define ISMED 1
# define ISNOTMED 0
# define UNDER 1
# define OVER 0

typedef struct	s_rot
{
	int	best;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
}				t_rot;

typedef struct	s_opti
{
	t_rot	rot;
	int		stack;
	int		size_a;
	int		size_b;
	int		max;
	int		cur;
	int		next;
	int		prev;
}				t_opti;

/*
**	Functions
*/

int				commit_instruction(t_list **a, t_list **b);
void			set_rot(t_rot *rot, int tab[4]);
void			get_elem_max(t_list *tmp, int size, t_opti *op);
void			push_back(t_list **a, t_list **b, t_opti *op,
													void (*funp[11])());

/*
**	algo.c
*/

void			insert_elem_a(t_list **a, t_list **b, t_opti *op,
													void (*funp[11])());
void			insert_elem_b(t_list **a, t_list **b, t_opti *op,
													void (*funp[11])());

/*
**	algo_helpers.c
*/

void			print_commit(t_list **a, t_list **b, void (*funp[11])(),
															t_opti *op);
void			update_rot(t_opti *op, t_rot rot);
void			rot_init(t_rot *rot);
#endif
