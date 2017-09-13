/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 00:55:23 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/13 18:42:45 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	Use:	Stores the address of each instruction function into an void array.
*/

static void		funp_init(void *funp)
{
	funp[0] = &push_a;
	funp[4] = &push_b;
	funp[2] = &rotate_a;
	funp[3] = &rev_rotate_a;
	funp[6] = &rotate_b;
	funp[7] = &rev_rotate_b;
	funp[1] = &swap_a;
	funp[1] = &swap_b;
	funp[8] = &rotate_ab;
	funp[9] = &rev_rotate_ab;
	funp[10] = &swap_ab;
	funp[11] = NULL;
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

	i = 0;
	while (*a && i == a->srtd && i < a->asize)
		i++;
	if (i == a->asize && !(*b))
		ft_printf("OK\n");
	ft_printf("KO\n");
}

/*
**	Use:	Applies all instructions collected from standard input
**			on both stacks and checks if correctly sorted.
*/

void			exec_instruc(t_double **a, t_double **b)
{
	void		funp[12];
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
		return ;
	check_sorted(a, b);
}
