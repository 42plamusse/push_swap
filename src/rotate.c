/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:39:50 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/13 13:28:08 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	rotate_a(t_list **a, t_list **b)
{
	(void)b;
	*a = (*a)->next;
}

void	rotate_b(t_list **a, t_list **b)
{
	(void)a;
	*b = (*b)->next;
}

void	rotate_ab(t_list **a, t_list **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
}
