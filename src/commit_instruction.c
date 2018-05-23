#include "push_swap.h"

int	check_a(t_list *tmp)
{
	t_elem	*elem;
	t_elem	*elem_next;
	t_elem	*elem_prev;


	if (!tmp)
		return (ERROR);
	elem = (t_elem*)(tmp->content);
	elem_next = (t_elem*)(tmp->next->content);
	elem_prev = (t_elem*)(tmp->prev->content);
	if (elem->nbr > elem_next->nbr && elem_next->nbr < elem_prev->nbr)
		return (SA);
	else if (elem->nbr > elem_prev->nbr)
		return (RRA);
	else
		return (ERROR);
}

int	check_b(t_list *tmp)
{
	t_elem	*elem;
	t_elem	*elem_next;
	t_elem	*elem_prev;


	if (!tmp)
		return (ERROR);
	elem = (t_elem*)(tmp->content);
	elem_next = (t_elem*)(tmp->next->content);
	elem_prev = (t_elem*)(tmp->prev->content);
	if (elem->nbr < elem_next->nbr && elem_next->nbr > elem_prev->nbr)
		return (SB);
	else if (elem->nbr < elem_prev->nbr)
		return (RRB);
	else
		return (ERROR);
}

int	get_instr(int ret_a, int ret_b, int stack)
{
	if (ret_a == ERROR && ret_b == ERROR)
	{
		if (stack == A)
			return (PB);
		if (stack == B)
			return (PA);
	}
	else if (ret_a == SA && ret_b == SB)
		return (SS);
	else if (ret_a == RRA && ret_b == RRB)
		return (RRR);
	else if (ret_a == SA)
		return (SA);
	else if (ret_a == RRA)
		return (RRA);
	else if (ret_b == SB)
		return (SB);
	else if (ret_b == RRB)
		return (RRB);
	return (ERROR);	
}

int	commit_instruction(t_list **a, t_list **b)
{
	void	(*funp[11])();
	int	instr;
	int	ret_a;
	int	ret_b;

	funp_init(funp);
	ft_lst2c_print(*a);
	while (check_sorted(*a))
	{

		while (*a && check_sorted(*a) == ERROR)
		{
			ret_a = check_a(*a);
			ret_b = check_b(*b);
			instr = get_instr(ret_a, ret_b, A);
			funp[instr](a, b);
			print_instr(instr);
			ft_lst2c_print(*a);
			ft_lst2c_print(*b);
		}
ft_printf("A VIDE OU SORTED\n");
		while (*b)
		{
			ret_a = check_a(*a);
			ret_b = check_b(*b);
			instr = get_instr(ret_a, ret_b, B);
			funp[instr](a, b);
			print_instr(instr);
			ft_lst2c_print(*a);
			ft_lst2c_print(*b);
		}
ft_printf("B VIDE\n");
	}
	return (0);
}
