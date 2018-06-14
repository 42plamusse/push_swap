/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:15:29 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/14 16:01:14 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	rev_rotate_a(t_list **a, t_list **b)
{
	(void)b;
	if (*a)
		*a = (*a)->prev;
	else
		exit(1);
}

void	rev_rotate_b(t_list **a, t_list **b)
{
	(void)a;
	if (*b)
		*b = (*b)->prev;
	else
		exit(1);
}

void	rev_rotate_ab(t_list **a, t_list **b)
{
	if (*a && *b)
	{
		*a = (*a)->prev;
		*b = (*b)->prev;
	}
	else
		exit(1);
}
