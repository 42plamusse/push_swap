/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:00:43 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/25 20:23:55 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	swap_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	(void)b;
	printf("in\n");
	(*a)->next->prev = (*a)->prev;
	printf("out\n");
	(*a)->prev->next = (*a)->next;
	tmp = (*a)->next;
	(*a)->prev = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}
	
void	swap_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	(*b)->next->prev = (*b)->prev;
	(*b)->prev->next = (*b)->next;
	tmp = (*b)->next;
	(*b)->prev = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	tmp = *a;
	tmp = 0;
}

void	swap_ab(t_list **a, t_list **b)
{
	swap_a(a, b);
	swap_b(a, b);
}
