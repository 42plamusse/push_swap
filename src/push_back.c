#include "push_swap.h"

void	push_back(t_list **a, t_list **b, t_opti *op)
{
	int	i;
	t_list	*tmp;
	int	rb;
	int	rrb;
	int	cur;

	get_elem_max(*b, op);
	i = 0;
	rb = 0;
	rrb = 0;
	tmp = *b;
	cur = ((t_elem*)(tmp->content))->nbr;
	while (i < op->size_b && cur != op->max)	
	{
		i++;
		tmp = tmp->next;
		rb = i;
		rrb = op->size_b - i;
		cur = ((t_elem*)(tmp->content))->nbr;
	}
	if (rb < rrb)
	{
		while (rb)
		{
			rotate_b(a, b);
			rb--;
		}
	}
	else
	{
		while (rrb)
		{
			rev_rotate_b(a, b);
			rrb--;
		}
	}
	while (*b)
		push_a(a, b);
}
