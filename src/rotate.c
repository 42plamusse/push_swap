/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:39:50 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/26 18:38:11 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	rotate_a(t_list **a, t_list **b)
{
	(void)b;
	*a = (*a)->next;
	ft_printf("ra\n");
}

void	rotate_b(t_list **a, t_list **b)
{
	(void)a;
	*b = (*b)->next;
	ft_printf("rb\n");
}

void	rotate_ab(t_list **a, t_list **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	ft_printf("rr\n");
}
