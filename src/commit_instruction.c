/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commit_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:52:04 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/13 16:56:37 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate_sort(t_list **a, t_list **b, t_opti *op, void (*funp[11])())
{
	int		i;
	t_list	*tmp;

	get_elem_max(*a, op->size_a, op);
	i = 1;
	op->rot.ra = 1;
	op->rot.rra = op->size_a;
	tmp = *a;
	op->cur = ((t_elem*)(tmp->content))->nbr;
	while (i++ < op->size_a && op->cur != op->max)
	{
		tmp = tmp->next;
		op->rot.ra = i;
		op->rot.rra = op->size_a - i;
		op->cur = ((t_elem*)(tmp->content))->nbr;
	}
	if (op->rot.ra < op->rot.rra)
		op->rot.rra = 0;
	else
		op->rot.ra = 0;
	print_commit(a, b, funp, op);
}

static void	opti_update(t_list *a, t_list *b, t_opti *op)
{
	op->size_a = ft_lst2c_len(a);
	op->size_b = ft_lst2c_len(b);
	op->rot.best = op->size_a + op->size_b;
	op->rot.ra = 0;
	op->rot.rra = 0;
	op->rot.rb = 0;
	op->rot.rrb = 0;
	op->rot.rr = 0;
	op->rot.rrr = 0;
}

int			commit_instruction(t_list **a, t_list **b)
{
	void	(*funp[11])();
	t_opti	op;

	funp_init(funp);
	opti_update(*a, *b, &op);
	if (op.size_a < 2)
		return (SUCCESS);
	while (op.size_a >= 2 && check_rotate_sorted(*a) == ERROR)
	{
		if (op.size_b < 2)
			print_instr(a, b, funp, PB);
		else
			insert_elem_b(a, b, &op, funp);
		opti_update(*a, *b, &op);
	}
	while (*b)
	{
		insert_elem_a(a, b, &op, funp);
		opti_update(*a, *b, &op);
	}
	rotate_sort(a, b, &op, funp);
	return (SUCCESS);
}
