/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:19:19 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/27 15:59:12 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	push_a(t_double **a, t_double **b)
{
	t_double	*tmp;

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

void	push_b(t_double **a, t_double **b)
{
	t_double	*tmp;

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
