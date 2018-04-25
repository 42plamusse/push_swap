/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:15:29 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/25 20:17:44 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	rev_rotate_a(t_list **a, t_list **b)
{
	t_list	**tmp;

	*a = (*a)->prev;
	tmp = b;
}

void	rev_rotate_b(t_list **a, t_list **b)
{
	t_list	**tmp;

	*b = (*b)->prev;
	tmp = a;
}

void	rev_rotate_ab(t_list **a, t_list **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
}
