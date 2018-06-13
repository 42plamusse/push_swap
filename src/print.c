/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:37:46 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/13 15:38:16 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_instr(t_list **a, t_list **b, void (*funp[11])(), int instr)
{
	funp[instr](a, b);
	if (instr == PA)
		ft_printf("pa\n");
	else if (instr == PB)
		ft_printf("pb\n");
	else if (instr == RA)
		ft_printf("ra\n");
	else if (instr == RRA)
		ft_printf("rra\n");
	else if (instr == RB)
		ft_printf("rb\n");
	else if (instr == RRB)
		ft_printf("rrb\n");
	else if (instr == SA)
		ft_printf("sa\n");
	else if (instr == SB)
		ft_printf("sb\n");
	else if (instr == RR)
		ft_printf("rr\n");
	else if (instr == RRR)
		ft_printf("rrr\n");
	else if (instr == SS)
		ft_printf("ss\n");
}

void	ft_lst2c_print_rev(t_list *lst)
{
	t_list		*tmp;
	t_elem		*elem;
	int			len;

	if (!lst)
		return ;
	len = ft_lst2c_len(lst) + 1;
	tmp = lst;
	while (len--)
	{
		elem = (t_elem*)tmp->content;
		ft_printf("%d", elem->nbr);
		if (len)
			ft_printf("_");
		else
			ft_printf("\n");
		tmp = tmp->prev;
	}
}

void	ft_lst2c_print(t_list *lst)
{
	t_list		*tmp;
	t_elem		*elem;
	int			len;

	if (!lst)
		return ;
	len = ft_lst2c_len(lst);
	tmp = lst;
	while (len--)
	{
		elem = (t_elem*)tmp->content;
		ft_printf("%d", elem->nbr);
		if (len)
			ft_printf("_");
		else
			ft_printf("\n");
		tmp = tmp->next;
	}
}
