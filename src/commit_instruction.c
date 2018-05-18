#include "push_swap.h"

int	commit_instruction(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_elem	*elem;
	t_elem	*elem_next;
	t_elem	*elem_prev;

	while (check_sorted(*a))
	{

		while (*a && check_sorted(*a) == ERROR)
		{
			tmp = *a;
			elem = (t_elem*)(tmp->content);
			elem_next = (t_elem*)(tmp->next->content);
			elem_prev = (t_elem*)(tmp->prev->content);
			if (elem->nbr > elem_next->nbr)
			{
				swap_a(a, b);
				ft_printf("sa\n");
			}
			else if (elem->nbr > elem_prev->nbr)
			{
				rev_rotate_a(a, b);
				ft_printf("rra\n");
			}
			else
			{
				push_b(a, b);
				ft_printf("pb\n");
			}
		}
		while (*b)
		{
			tmp = *b;
			elem = (t_elem*)(tmp->content);
			elem_next = (t_elem*)(tmp->next->content);
			elem_prev = (t_elem*)(tmp->prev->content);
			if (elem->nbr > elem_next->nbr)
			{
				swap_b(a, b);
				ft_printf("sb\n");
			}
			else if (elem->nbr > elem_prev->nbr)
			{
				rev_rotate_b(a, b);
				ft_printf("rrb\n");
			}
			else
			{
				push_a(a, b);
				ft_printf("pa\n");
			}

		}
	}
	return (0);
}
