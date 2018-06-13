/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:42:40 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/13 15:25:51 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_commit(t_list **a, t_list **b, void (*funp[11])(), t_opti *op)
{
	int		i;

	i = 0;
	while (i++ < op->rot.ra)
		print_instr(a, b, funp, RA);
	i = 0;
	while (i++ < op->rot.rb)
		print_instr(a, b, funp, RB);
	i = 0;
	while (i++ < op->rot.rra)
		print_instr(a, b, funp, RRA);
	i = 0;
	while (i++ < op->rot.rrb)
		print_instr(a, b, funp, RRB);
	i = 0;
	while (i++ < op->rot.rr)
		print_instr(a, b, funp, RR);
	i = 0;
	while (i++ < op->rot.rrr)
		print_instr(a, b, funp, RRR);
}

void	update_rot(t_opti *op, t_rot rot)
{
	op->rot.best = rot.best;
	op->rot.ra = rot.ra;
	op->rot.rb = rot.rb;
	op->rot.rra = rot.rra;
	op->rot.rrb = rot.rrb;
	op->rot.rr = rot.rr;
	op->rot.rrr = rot.rrr;
}

void	rot_init(t_rot *rot)
{
	rot->best = 0;
	rot->ra = 0;
	rot->rra = 0;
	rot->rb = 0;
	rot->rrb = 0;
	rot->rr = 0;
	rot->rrr = 0;
}

void	get_elem_max(t_list *tmp, int size, t_opti *op)
{
	int	i;
	int	cur;

	op->max = ((t_elem*)(tmp->content))->nbr;
	i = 0;
	while (i < size)
	{
		cur = ((t_elem*)(tmp->content))->nbr;
		if (cur > op->max)
			op->max = cur;
		tmp = tmp->next;
		i++;
	}
}
