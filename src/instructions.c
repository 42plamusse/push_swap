/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 00:55:23 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/28 15:39:19 by plamusse         ###   ########.fr       */
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
	return (-1);
}

/*
**	Use:	Checks if stack A is sorted.
*/

static void		check_sorted(t_double **a, t_double **b)
{
	int			i;
	t_double	*tmp;
	int			end;

	i = 0;
	tmp = *a;
	end = 0;
	while (tmp && i == tmp->srtd && !end)
	{
		i++;
		tmp = tmp->next;
		if (tmp == *a)
			end = 1;
	}
	if (*a && tmp == *a && !(*b))
		ft_printf("OK\n");
	ft_printf("KO\n");
}

/*
**	Use:	Applies all instructions collected from standard input
**			on both stacks and checks if correctly sorted.
*/

void			exec_instruc(t_double **a, t_double **b)
{
	void		(*funp[11])();
	char		*instr;
	int			ret;
	int			i;

	funp_init(funp);
	while ((ret = get_next_line(0, &instr)) && ret != -1 && i != -1)
	{
		i = instr_index(instr);
		if (i != -1)
			funp[i](a, b);
	}
	if (ret == -1 || i == -1)
	{
		ft_printf("error\n");
		return ;
	}
	check_sorted(a, b);
}
