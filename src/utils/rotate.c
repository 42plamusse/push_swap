/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:39:50 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/26 17:03:07 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate_a(t_double **a, t_double **b)
{
	t_double	**tmp;

	*a = (*a)->next;
	tmp = b;
}

void	rotate_b(t_double **a, t_double **b)
{
	t_double	**tmp;

	*b = (*b)->next;
	tmp = a;
}

void	rotate_ab(t_double **a, t_double **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
}
