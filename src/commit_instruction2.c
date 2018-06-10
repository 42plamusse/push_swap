#include "push_swap.h"

//int	get_instr(t_list *a, t_list *b, int stack)
//{
//	if (stack == A)
//	{
//		op.ismed_cur = check_median_a(a, &op);
//		op.ismed_next = check_median_a(a->next, &op);
//	}
//	else if (stack == B)
//	{
//		op.ismed_cur = check_median_b(b, &op);
//		op.ismed_next = check_median_b(b->next, &op);
//	}
//	if ((op.ismed_cur && op.ismed_next) || (!op.ismed_cur && !op.ismed_next))
//	{
//		if (op.ret_a == SA && op.ret_b == SB)
//			return (SS);
//		if (op.ret_a == SA)
//			return (SA);
//		if (op.ret_b == SB)
//			return (SB);
//	}
//	if (stack == A)
//	{
//		if (op.ret_b == SB)
//			return (SB);
//		else if (op.ismed_cur)
//			return (PB);
//		else
//			return (RA);			
//	}
//	else if (stack == B)
//	{
//		if (op.ret_a == SA)
//			return (SA);
//		else if (op.ismed_cur)
//			return (PA);
//		else
//			return (RB);			
//	}
//	return (ERROR);	
//}
//

static void	init_opti(t_list *tmp, t_opti *op)
{
	op->cur = ((t_elem*)(tmp->content))->srtd;
	op->next = ((t_elem*)(tmp->next->content))->srtd;
	op->prev = ((t_elem*)(tmp->prev->content))->srtd;
}

int	check_double_instr(int ret_a, int ret_b, t_opti *op,  int stack)
{
	if (ret_a == SA && ret_b == SB)
		return (SS);
	else if (ret_a == RA && ret_b == RB)
		return (RR);
	else if (ret_a == RRA && ret_b == RRB)
		return (RRR);
	else if ((ret_a == PB && ret_b == PA) || (ret_a == PB && ret_b == ERROR) || (ret_b == PA && ret_a == ERROR))
	{
		op->i++;
		if (stack == A)
			return (PB);
		else if (stack == B)
			return (PA);

	}
	return (ERROR);
}

int	check_a(t_list *tmp, t_opti *op)
{
	if (!tmp || ft_lst2c_len(tmp) == 1 || check_sorted(tmp) == SUCCESS)
		return (ERROR);
	init_opti(tmp, op);
ft_printf("med a%i\n", op->med_a);
	if (op->cur < op->med_a || !op->med_a)
	{
		if (op->next < op->cur && op->next < op->prev)
			return (SA);
		else if (op->prev < op->cur)
			return (RRA);
		else
			return (PB);
	}
	else
	{
		if (op->prev < op->med_a)
			return (RRA);
		else if (op->next > op->med_a && op->next < op->cur)
			return (SA);
		else
			return (RA);
	}
}

int	check_b(t_list *tmp, t_opti *op)
{
	if (!tmp || ft_lst2c_len(tmp) == 1 || check_rev_sorted(tmp) == SUCCESS)
		return (ERROR);
	init_opti(tmp, op);
ft_printf("med b%i\n", op->med_b);
	if (op->cur >= op->med_b || !op->med_b)
	{
		if (op->next > op->cur && op->next > op->prev)
			return (SB);
		else if (op->prev > op->cur)
			return (RRB);
		else
			return (PA);
	}
	else
	{
		if (op->prev > op->med_b)
			return (RRB);
		else if (op->next < op->med_b && op->next > op->cur)
			return (SB);
		else
			return (RB);
	}
}

void	update_median(t_list *a, t_list *b, t_opti *op, int stack)
{
	if (stack == A)
	{
		if (op->i >= op->div)
		{
			op->size_stack = ft_lst2c_len(a);
			op->med_a = op->med_a + op->size_stack / 2;
			op->div = op->div / 2;
			op->i = 0;
			op->med_b = 0;
		}
	}
	else
	{
		if (op->i >= op->div)
		{
			op->size_stack = ft_lst2c_len(b);
			if ((op->med_b = op->med_b - op->size_stack / 2) < 0)
				op->med_b = 0;
			op->div = op->div / 2;
			op->i = 0;
			op->med_a = 0;
		}
	}

}

int	get_instr(t_list *a, t_list *b, t_opti *op, int stack)
{
	int	ret_a;
	int	ret_b;
	int	dbl;

	update_median(a, b, op, stack);	
	ret_a = check_a(a, op);
ft_printf("i %i\n", op->i);
ft_printf("div %i\n", op->div);
	ret_b = check_b(b, op);
	if ((dbl = check_double_instr(ret_a, ret_b, op, stack)) != ERROR)
		return (dbl);
	else if (ret_a != PB)
		return (ret_a);
	else
		return (ret_b);
}

void	sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	k;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		tmp = tab[i];
		while (j < len)
		{
			if (tab[j] < tmp)
			{
				tmp = tab[j];
				k = j;
			}
			j++;
		}
		if (tmp != tab[i])
		{
			tab[k] = tab[i];
			tab[i] = tmp;
		}
		i++;
	}
}

int	sort_label_stack(t_list *stack, t_opti *op)
{
	int	*tab;
	t_list	*tmp;
	int	i;
	int	j;
	int	nbr;

	if (!stack)
		return (ERROR);
	if (!(tab = (int*)malloc(sizeof(int) * op->size_stack)))
		return (ERROR);
	i = 0;
	tmp = stack;
	while (i < op->size_stack)
	{
		tab[i++] = ((t_elem*)tmp->content)->nbr;
		tmp = tmp->next;
	}
	sort_tab(tab, op->size_stack);
	i = 0;
	while (i < op->size_stack)
	{
		nbr = ((t_elem*)tmp->content)->nbr;
		j = 0;
		while (nbr != tab[j])
			j++;
		((t_elem*)tmp->content)->srtd = j;
		i++;
		tmp = tmp->next;

	}
	ft_memdel((void**)&tab);
	return (SUCCESS);
}

void	create_median_a(t_list *a, t_opti *op)
{
	op->size_stack = ft_lst2c_len(a);
	op->med_a = op->size_stack / 2;
	if (op->first)
	{
		op->med_b = op->med_a / 2;
		op->first = 0;
	}
	else
		op->med_b = 0;
	op->i = 0;
	op->div = op->size_stack / 2;

}

void	create_median_b(t_list *b, t_opti *op)
{
	op->size_stack = ft_lst2c_len(b);
	op->med_b = op->size_stack / 2;
	op->med_a = 0;
	op->i = 0;
	op->div = op->size_stack / 2;

}

int	commit_instruction(t_list **a, t_list **b)
{
	void	(*funp[11])();
	int	instr;
	t_opti	op;

	op.size_stack = ft_lst2c_len(*a);
	op.first = 1;
	if (sort_label_stack(*a, &op) == ERROR)
		return (ERROR);
	funp_init(funp);
ft_lst2c_print(*a);
	while (check_sorted(*a))
	{
		create_median_a(*a, &op);
		while (*a && check_sorted(*a) == ERROR)
		{
			instr = get_instr(*a, *b, &op, A);
			funp[instr](a, b);
			print_instr(instr);
ft_lst2c_print(*a);
ft_lst2c_print(*b);
		}
		create_median_b(*b, &op);
		while (*b)
		{
			instr = get_instr(*a, *b, &op, B);
			funp[instr](a, b);
			print_instr(instr);
ft_lst2c_print(*a);
ft_lst2c_print(*b);
		}
	}
	return (SUCCESS);
}
