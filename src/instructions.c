/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 00:55:23 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/26 18:30:13 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
**	Use:	Stores the address of each instruction function into an void array.
*/

static void		funp_init(void (**funp)())
{

	funp[0] = push_a;
	funp[1] = &push_b;
	funp[2] = &rotate_a;
	funp[3] = &rev_rotate_a;
	funp[4] = &rotate_b;
	funp[5] = &rev_rotate_b;
	funp[6] = &swap_a;
	funp[7] = &swap_b;
	funp[8] = &rotate_ab;
	funp[9] = &rev_rotate_ab;
	funp[10] = &swap_ab;
}

/*
**	Use:	Returns the index corresponding to the instruction in funp array.
*/

static int		instr_index(char *instr)
{
	if (!ft_strcmp(instr, "pa"))
		return (0);
	else if (!ft_strcmp(instr, "pb"))
		return (1);
	else if (!ft_strcmp(instr, "ra"))
		return (2);
	else if (!ft_strcmp(instr, "rra"))
		return (3);
	else if (!ft_strcmp(instr, "rb"))
		return (4);
	else if (!ft_strcmp(instr, "rrb"))
		return (5);
	else if (!ft_strcmp(instr, "sa"))
		return (6);
	else if (!ft_strcmp(instr, "sb"))
		return (7);
	else if (!ft_strcmp(instr, "rr"))
		return (8);
	else if (!ft_strcmp(instr, "rrr"))
		return (9);
	else if (!ft_strcmp(instr, "ss"))
		return (10);
	return (ERROR);
}

/*
**	Use:	Checks if stack A is sorted.
*/

static void		check_sorted(t_list *a, t_list *b)
{
	t_list		*tmp;
	int			len;
	int			err;

	if (!a)
	{
		ft_printf("KO\n");
		return ;
	}
	len = ft_lst2c_len(a) - 1;
	tmp = a;
	err = 0;
	while (err != ERROR && len--)
	{
		if (((t_elem*)(tmp->content))->nbr > ((t_elem*)(tmp->next->content))->nbr)
			err = ERROR;
		tmp = tmp->next;
	}
	if (a && err != ERROR && !ft_lst2c_len(b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

/*
**	Use:	Applies all instructions collected from standard input
**			on both stacks and checks if correctly sorted.
*/

void			exec_instruc(t_list **a, t_list **b)
{
	void		(*funp[11])();
	char		*instr;
	int			ret;
	int			i;

	funp_init(funp);
	i = 0;
	while ((ret = get_next_line(0, &instr)) > 0 && i != ERROR)
	{
		printf("%s\n", instr);
		if ((i = instr_index(instr)) != ERROR)
			funp[i](a, b);
	ft_lst2c_print(*a);
	ft_lst2c_print_rev(*a);
	ft_lst2c_print(*b);
	ft_lst2c_print_rev(*b);
	}
	if (ret == ERROR || i == ERROR)
	{
		ft_printf("error\n");
		return ;
	}
	check_sorted(*a, *b);
}
