/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:15:29 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/13 13:28:22 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	rev_rotate_a(t_list **a, t_list **b)
{
	(void)b;
	*a = (*a)->prev;
}

void	rev_rotate_b(t_list **a, t_list **b)
{
	(void)a;
	*b = (*b)->prev;
}

void	rev_rotate_ab(t_list **a, t_list **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
}
