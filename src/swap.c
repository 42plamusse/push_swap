/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:00:43 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/26 17:38:13 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	swap_a(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*second;

	(void)b;
	first = *a;
	second = first->next;
	first->prev->next = second;
	second->prev = first->prev;
	second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	*a = second;
}

void	swap_b(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*second;

	(void)a;
	first = *b;
	second = first->next;
	first->prev->next = second;
	second->prev = first->prev;
	second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	*b = second;
}

void	swap_ab(t_list **a, t_list **b)
{
	swap_a(a, b);
	swap_b(a, b);
}
