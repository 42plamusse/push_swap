#include "push_swap.h"

int	check_a(t_list *tmp)
{
	t_elem	*elem;
	t_elem	*elem_next;
	//t_elem	*elem_prev;


	if (!tmp)
		return (ERROR);
	elem = (t_elem*)(tmp->content);
	elem_next = (t_elem*)(tmp->next->content);
	//elem_prev = (t_elem*)(tmp->prev->content);
	if (elem->nbr > elem_next->nbr)// && elem_next->nbr < elem_prev->nbr)
		return (SA);
	//	else if (elem->nbr > elem_prev->nbr)
	//		return (RRA);
	else
		return (ERROR);
}

int	check_b(t_list *tmp)
{
	t_elem	*elem;
	t_elem	*elem_next;
	//t_elem	*elem_prev;


	if (!tmp)
		return (ERROR);
	elem = (t_elem*)(tmp->content);
	elem_next = (t_elem*)(tmp->next->content);
	//elem_prev = (t_elem*)(tmp->prev->content);
	if (elem->nbr < elem_next->nbr)// && elem_next->nbr > elem_prev->nbr)
		return (SB);
	//	else if (elem->nbr < elem_prev->nbr)
	//		return (RRB);
	else
		return (ERROR);
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

int	check_median_a(t_list *stack, t_opti *op)
{
	int	*tab;
	t_list	*tmp;
	int	i;
	int	nbr;

	if (!stack)
		return (ERROR);
	if (!(tab = (int*)malloc(sizeof(int) * op->size_stack)))
		return (ERROR);
	i = 0;
	tmp = stack;
	nbr = ((t_elem*)tmp->content)->nbr;
	while (i < op->size_stack)
	{
		tab[i++] = ((t_elem*)tmp->content)->nbr;
		tmp = tmp->next;
	}
	sort_tab(tab, op->size_stack);
	i = 0;
	while (i <= op->med)
	{
		if (nbr == tab[i++])
			return (ISMED);
	}
	ft_memdel((void**)&tab);
	return (ISNOTMED);
}

int	check_median_b(t_list *stack, t_opti *op)
{
	int	*tab;
	t_list	*tmp;
	int	i;
	int	nbr;

	if (!stack)
		return (ERROR);
	if (!(tab = (int*)malloc(sizeof(int) * op->size_stack)))
		return (ERROR);
	i = 0;
	tmp = stack;
	nbr = ((t_elem*)tmp->content)->nbr;
	while (i < op->size_stack)
	{
		tab[i++] = ((t_elem*)tmp->content)->nbr;
		tmp = tmp->next;
	}
	sort_tab(tab, op->size_stack);
	i = op->med;
	while (i <= op->size_stack)
	{
		if (nbr == tab[i++])
			return (ISMED);
	}
	ft_memdel((void**)&tab);
	return (ISNOTMED);
}

int	get_instr(t_list *a, t_list *b, int stack)
{
	if (stack == A)
	{
		op.ismed_cur = check_median_a(a, &op);
		op.ismed_next = check_median_a(a->next, &op);
	}
	else if (stack == B)
	{
		op.ismed_cur = check_median_b(b, &op);
		op.ismed_next = check_median_b(b->next, &op);
	}
	if ((op.ismed_cur && op.ismed_next) || (!op.ismed_cur && !op.ismed_next))
	{
		if (op.ret_a == SA && op.ret_b == SB)
			return (SS);
		if (op.ret_a == SA)
			return (SA);
		if (op.ret_b == SB)
			return (SB);
	}
	if (stack == A)
	{
		if (op.ret_b == SB)
			return (SB);
		else if (op.ismed_cur)
			return (PB);
		else
			return (RA);			
	}
	else if (stack == B)
	{
		if (op.ret_a == SA)
			return (SA);
		else if (op.ismed_cur)
			return (PA);
		else
			return (RB);			
	}
	return (ERROR);	
}

static void	init_opti(t_list *a, t_list *b, t_opti *op)
{
	ret_a = 0;
	ret_b = 0;
	size_stack = 0;
	med = 0;
	cur = 0;
	next = 0;
	prev = 0;

	if (stack == A)
		op->size_stack = ft_lst2c_len(a);
	if (stack == B)
		op->size_stack = ft_lst2c_len(b);
	op->med = op->size_stack / 2;
	op->ismed_cur = 0;
	op->ismed_next = 0;
}

int	commit_instruction(t_list **a, t_list **b)
{
	void	(*funp[11])();
	int	instr;
	t_opti	op;

	init_opti(a, b, &op);
	sort_label_stack(*a);
	funp_init(funp);
	//ft_lst2c_print(*a);
	while (check_sorted(*a))
	{
		while (*a && check_sorted(*a) == ERROR)
		{
			get_median(*a, &op);
			instr = get_instr(*a, *b, A);
			funp[instr](a, b);
			print_instr(instr);
			//			ft_lst2c_print(*a);
			//			ft_lst2c_print(*b);
		}
		while (*b)
		{
			get_median(*b, &op);
			instr = get_instr(*a, *b, B);
			funp[instr](a, b);
			print_instr(instr);
			//			ft_lst2c_print(*a);
			//			ft_lst2c_print(*b);
		}
	}
	return (SUCCESS);
}
