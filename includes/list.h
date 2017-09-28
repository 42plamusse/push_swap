/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:47:46 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/27 16:58:57 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** f
*/

#ifndef LIST_H
# define LIST_H

/*
**	 HEADERS
*/

# include "utils.h"

/*
**	STRUCTURES
*/

/*
**	Use:	Element of the double circular chained list used for the navigation
** 			in stacks A and B.
*/

typedef struct s_double	t_double;
struct					s_double
{
	int			elem;
	int			cur;
	int			srtd;
	int			prio;
	t_double	*next;
	t_double	*prev;
};

void	push_a(t_double **a, t_double **b);
void	push_b(t_double **a, t_double **b);
void	swap_a(t_double **a, t_double **b);
void	swap_b(t_double **a, t_double **b);
void	swap_ab(t_double **a, t_double **b);
void	rotate_a(t_double **a, t_double **b);
void	rotate_b(t_double **a, t_double **b);
void	rotate_ab(t_double **a, t_double **b);
void	rev_rotate_a(t_double **a, t_double **b);
void	rev_rotate_b(t_double **a, t_double **b);
void	rev_rotate_ab(t_double **a, t_double **b);
#endif
