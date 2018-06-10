#include "push_swap.h"

void	print_rot(t_rot rot)
{
	ft_printf("rot->best %i\n", rot.best);
	ft_printf("rot->ra %i\n", rot.ra);
	ft_printf("rot->rb %i\n", rot.rb);
	ft_printf("rot->rra %i\n", rot.rra);
	ft_printf("rot->rrb %i\n", rot.rrb);
	ft_printf("rot->rr %i\n", rot.rr);
	ft_printf("rot->rrr %i\n", rot.rrr);
	ft_printf("\n");
}

void	compute_rot(t_rot *rot)
{
	int	tab[4];
	int	i;
	int	tmp;
	int	ret;

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
	i = 0;
	ret = 0;
	tmp = tab[i];
	while (i < 4)
	{	
		if (tab[i] < tmp)
		{
			tmp = tab[i];
			ret = i;
		}
		i++;
	}
	rot->best = tmp;
	set_rot(rot, ret);
}
void	get_shorter_path(t_list *b, t_opti *op, t_rot *rot)
{
	int i;
	t_list	*tmp;
	int	ret;

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
	if (i == 0)
		rot->rrb = 0;
	else
		rot->rrb = op->size_b - i;
	compute_rot(rot);
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

void	get_elem_max(t_list *b, t_opti *op)
{
	int	i;
	t_list	*tmp;
	int	cur;

	tmp = b;
	op->max = ((t_elem*)(tmp->content))->nbr;
	i = 0;
	while (i < op->size_b)
	{
		cur = ((t_elem*)(tmp->content))->nbr;
		if (cur > op->max)
			op->max = cur; 
		tmp = tmp->next;
		i++;
	}
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

void	insert_elem(t_list **a, t_list **b, t_opti *op)
{
	int	i;
	t_list	*tmp;
	t_rot	rot;

	tmp = *a;
	i = 0;
	rot_init(&rot);
	get_elem_max(*b, op);
	while (i < op->size_a)
	{
		op->cur = ((t_elem*)(tmp->content))->nbr;
		get_shorter_path(*b, op, &rot);
		if (rot.best < op->rot.best)
			update_rot(op, rot);
		tmp = tmp->next;
		i++;
		rot.ra = i;
		rot.rra = op->size_a - i;
	}
	i = 0;
	while (i < op->rot.ra)
	{
		rotate_a(a, b);
		i++;
	}
	i = 0;
	while (i < op->rot.rb)
	{
		rotate_b(a, b);
		i++;
	}
	i = 0;
	while (i < op->rot.rra)
	{
		rev_rotate_a(a, b);
		i++;
	}
	i = 0;
	while (i < op->rot.rrb)
	{
		rev_rotate_b(a, b);
		i++;
	}
	i = 0;
	while (i < op->rot.rr)
	{
		rotate_ab(a, b);
		i++;
	}
	i = 0;
	while (i < op->rot.rrr)
	{
		rev_rotate_ab(a, b);
		i++;
	}
	push_b(a, b);
}

void	opti_update(t_list *a, t_list *b, t_opti *op)
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

int	commit_instruction(t_list **a, t_list **b)
{
	void	(*funp[11])();
	t_opti	op;

	(void)b;
	funp_init(funp);
	opti_update(*a, *b, &op);
	ft_lst2c_print(*a);
	//while (op.size_a >= 2 && check_sorted(*a) == ERROR)
	while (*a)
	{
		if (op.size_b < 2)
			push_b(a, b);
		else
			insert_elem(a, b, &op);
		opti_update(*a, *b, &op);
ft_lst2c_print(*a);
ft_lst2c_print(*b);
	}
	push_back(a, b, &op);
	return (SUCCESS);
}
