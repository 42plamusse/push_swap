/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:19:19 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/25 20:17:32 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	(*b)->prev->next = (*b)->next;	
	(*b)->next->prev = (*b)->prev;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	tmp->prev = (*a)->prev;
	(*a)->prev->next = tmp;
	(*a)->prev = tmp;
	*a = tmp;
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	(*a)->prev->next = (*a)->next;	
	(*a)->next->prev = (*a)->prev;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	tmp->prev = (*b)->prev;
	(*b)->prev->next = tmp;
	(*b)->prev = tmp;
	*b = tmp;
}
