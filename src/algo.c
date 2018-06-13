/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:37:37 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/13 15:24:46 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compute_rot(t_rot *rot)
{
	int	tab[4];

	tab[0] = rot->ra + rot->rrb;
	tab[1] = rot->rb + rot->rra;
	if (rot->ra >= rot->rb)
		tab[2] = rot->ra;
	else
		tab[2] = rot->rb;
	if (rot->rra >= rot->rrb)
		tab[3] = rot->rra;
	else
		tab[3] = rot->rrb;
	set_rot(rot, tab);
}

static void	get_shorter_path_a(t_list *tmp, t_opti *op, t_rot *rot)
{
	int		i;
	int		ret;

	i = 0;
	ret = ERROR;
	while (i < op->size_a && ret == ERROR)
	{
		op->prev = ((t_elem *)(tmp->prev->content))->nbr;
		op->next = ((t_elem *)(tmp->content))->nbr;
		if (op->prev == op->max)
		{
			if (op->cur > op->max || op->cur < op->next)
				ret = SUCCESS;
		}
		else if (op->cur < op->next && op->cur > op->prev)
			ret = SUCCESS;
		if (ret == ERROR)
			i++;
		tmp = tmp->next;
	}
	rot->ra = i;
	rot->rra = op->size_a - i;
	compute_rot(rot);
}

static void	get_shorter_path_b(t_list *b, t_opti *op, t_rot *rot)
{
	int		i;
	t_list	*tmp;
	int		ret;

	i = 0;
	tmp = b;
	ret = ERROR;
	while (i < op->size_b && ret == ERROR)
	{
		op->prev = ((t_elem *)(tmp->prev->content))->nbr;
		op->next = ((t_elem *)(tmp->content))->nbr;
		if (op->next == op->max)
		{
			if (op->cur > op->max || op->cur < op->prev)
				ret = SUCCESS;
		}
		else if (op->cur < op->prev && op->cur > op->next)
			ret = SUCCESS;
		if (ret == ERROR)
			i++;
		tmp = tmp->next;
	}
	rot->rb = i;
	rot->rrb = op->size_b - i;
	compute_rot(rot);
}

void		insert_elem_a(t_list **a, t_list **b, t_opti *op,
		void (*funp[11])())
{
	int		i;
	t_list	*tmp;
	t_rot	rot;

	tmp = *b;
	i = 0;
	rot_init(&rot);
	get_elem_max(*a, op->size_a, op);
	while (i < op->size_b)
	{
		op->cur = ((t_elem*)(tmp->content))->nbr;
		get_shorter_path_a(*a, op, &rot);
		if (rot.best < op->rot.best)
			update_rot(op, rot);
		tmp = tmp->next;
		i++;
		rot.rb = i;
		rot.rrb = op->size_b - i;
	}
	print_commit(a, b, funp, op);
	print_instr(a, b, funp, PA);
}

void		insert_elem_b(t_list **a, t_list **b, t_opti *op,
		void (*funp[11])())
{
	int		i;
	t_list	*tmp;
	t_rot	rot;

	tmp = *a;
	i = 0;
	rot_init(&rot);
	get_elem_max(*b, op->size_b, op);
	while (i < op->size_a)
	{
		op->cur = ((t_elem*)(tmp->content))->nbr;
		get_shorter_path_b(*b, op, &rot);
		if (rot.best < op->rot.best)
			update_rot(op, rot);
		tmp = tmp->next;
		i++;
		rot.ra = i;
		rot.rra = op->size_a - i;
	}
	print_commit(a, b, funp, op);
	print_instr(a, b, funp, PB);
}
