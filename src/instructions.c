/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:33:47 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/13 16:42:32 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	Use:	Returns the index corresponding to the instruction in funp array.
*/

static int	instr_index(char *instr)
{
	if (!ft_strcmp(instr, "pa"))
		return (PA);
	else if (!ft_strcmp(instr, "pb"))
		return (PB);
	else if (!ft_strcmp(instr, "ra"))
		return (RA);
	else if (!ft_strcmp(instr, "rra"))
		return (RRA);
	else if (!ft_strcmp(instr, "rb"))
		return (RB);
	else if (!ft_strcmp(instr, "rrb"))
		return (RRB);
	else if (!ft_strcmp(instr, "sa"))
		return (SA);
	else if (!ft_strcmp(instr, "sb"))
		return (SB);
	else if (!ft_strcmp(instr, "rr"))
		return (RR);
	else if (!ft_strcmp(instr, "rrr"))
		return (RRR);
	else if (!ft_strcmp(instr, "ss"))
		return (SS);
	return (ERROR);
}

/*
**	Use:	Applies all instructions collected from standard input
**			on both stacks and checks if correctly sorted.
*/

void		exec_instruc(t_list **a, t_list **b)
{
	void		(*funp[11])();
	char		*instr;
	int			ret;
	int			i;

	funp_init(funp);
	i = 0;
	while ((ret = get_next_line(0, &instr)) > 0 && i != ERROR)
	{
		if ((i = instr_index(instr)) != ERROR)
			funp[i](a, b);
		free(instr);
	}
	if (ret == ERROR || i == ERROR)
	{
		ft_printf("Error\n");
		return ;
	}
	if (!*b && check_sorted(*a) == SUCCESS)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
