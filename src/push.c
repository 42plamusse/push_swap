/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:19:19 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/26 18:32:24 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	if (*b == (*b)->next)
		*b = NULL;
	else
		*b = tmp->next;
	if (!*a)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = *a;
		tmp->prev = (*a)->prev;
		(*a)->prev->next = tmp;
		(*a)->prev = tmp;
	}
	*a = tmp;
	ft_printf("pa\n");
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	if (*a == (*a)->next)
		*a = NULL;
	else
		*a = tmp->next;
	if (!*b)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = *b;
		tmp->prev = (*b)->prev;
		(*b)->prev->next = tmp;
		(*b)->prev = tmp;
	}
	*b = tmp;
	ft_printf("pb\n");
}
