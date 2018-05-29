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

void	init_opti(t_list *a, t_list *b, t_opti *op, int stack)
{
	op->ret_a = check_a(a);
	op->ret_b = check_b(b);
	if (stack == A)
		op->size_stack = ft_lst2c_len(a);
	if (stack == B)
		op->size_stack = ft_lst2c_len(b);
	op->med = op->size_stack / 2;
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
//	i = 0;
//	while (i < op->size_stack)
//		ft_printf("%i ", tab[i++]);
	i = 0;
//	ft_printf("med = %i\n", op->med);
	while (i <= op->med)
	{
		if (nbr == tab[i++])
			return (PB);
	}
	return (RA);
}

int	check_median_b(t_list *stack, t_opti *op)
{
	int	*tab;
	t_list	*tmp;
	int	i;
	int	nbr;

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
//	i = 0;
//	while (i < op->size_stack)
//		ft_printf("%i ", tab[i++]);
//	ft_printf("med = %i\n", op->med);
	i = op->med;
	while (i <= op->size_stack)
	{
	//ft_printf("nbr= %i\n", nbr);
	//ft_printf("tab i= %i\n", tab[i]);
		if (nbr == tab[i++])
			return (PA);
	}
	return (RB);
}

int	get_instr(t_list *a, t_list *b, int stack)
{
	t_opti	op;

	init_opti(a, b, &op, stack);
	if (op.ret_a == ERROR && op.ret_b == ERROR)
	{
		if (stack == A)
			return (check_median_a(a, &op));
		if (stack == B)
			return (check_median_b(b, &op));
	}
	else if (op.ret_a == SA && op.ret_b == SB)
		return (SS);
//	else if (op.ret_a == RRA && op.ret_b == RRB)
//		return (RRR);
	else if (op.ret_a == SA)
		return (SA);
//	else if (op.ret_a == RRA)
//		return (RRA);
	else if (op.ret_b == SB)
		return (SB);
//	else if (op.ret_b == RRB)
//		return (RRB);
	return (ERROR);	
}

int	commit_instruction(t_list **a, t_list **b)
{
	void	(*funp[11])();
	int	instr;

	funp_init(funp);
//	ft_lst2c_print(*a);
	while (check_sorted(*a))
	{

		while (*a && check_sorted(*a) == ERROR)
		{
			instr = get_instr(*a, *b, A);
			funp[instr](a, b);
			print_instr(instr);
//	ft_lst2c_print(*a);
//	ft_lst2c_print(*b);
		}
		while (*b)
		{
			instr = get_instr(*a, *b, B);
			funp[instr](a, b);
			print_instr(instr);
//	ft_lst2c_print(*a);
//	ft_lst2c_print(*b);
		}
	}
	return (0);
}
