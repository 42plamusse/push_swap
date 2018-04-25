/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:39:50 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/25 20:18:08 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	rotate_a(t_list **a, t_list **b)
{
	t_list	**tmp;

	*a = (*a)->next;
	tmp = b;
}

void	rotate_b(t_list **a, t_list **b)
{
	t_list	**tmp;

	*b = (*b)->next;
	tmp = a;
}

void	rotate_ab(t_list **a, t_list **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
}
