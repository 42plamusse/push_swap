/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:00:43 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/27 16:34:32 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_a(t_double **a, t_double **b)
{
	t_double	*tmp;

	(*a)->next->prev = (*a)->prev;
	(*a)->prev->next = (*a)->next;
	tmp = (*a)->next;
	(*a)->prev = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	tmp = *b;
	tmp = 0;
}
	
void	swap_b(t_double **a, t_double **b)
{
	t_double	*tmp;

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

void	swap_ab(t_double **a, t_double **b)
{
	swap_a(a, b);
	swap_b(a, b);
}
