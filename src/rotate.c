/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:39:50 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/14 16:03:36 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	rotate_a(t_list **a, t_list **b)
{
	(void)b;
	if (*a)
		*a = (*a)->next;
	else
		exit(1);
}

void	rotate_b(t_list **a, t_list **b)
{
	(void)a;
	if (*b)
		*b = (*b)->next;
	else
		exit(1);
}

void	rotate_ab(t_list **a, t_list **b)
{
	if (*a && *b)
	{
		rotate_a(a, b);
		rotate_b(a, b);
	}
	else
		exit(1);
}
