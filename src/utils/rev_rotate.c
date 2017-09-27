/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:15:29 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/27 12:18:39 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rev_rotate_a(t_double **a, t_double **b)
{
	t_double	**tmp;

	*a = (*a)->prev;
	tmp = b;
}

void	rev_rotate_b(t_double **a, t_double **b)
{
	t_double	**tmp;

	*b = (*b)->prev;
	tmp = a;
}

void	rev_rotate_ab(t_double **a, t_double **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
}
