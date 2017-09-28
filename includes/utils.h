/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:30:02 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/28 15:17:09 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
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

/*
**	FUNCTIONS
*/

int				create_stack(int argc, char *argv[], t_double **a);
void			push_a(t_double **a, t_double **b);
void			push_b(t_double **a, t_double **b);
void			swap_a(t_double **a, t_double **b);
void			swap_b(t_double **a, t_double **b);
void			swap_ab(t_double **a, t_double **b);
void			rotate_a(t_double **a, t_double **b);
void			rotate_b(t_double **a, t_double **b);
void			rotate_ab(t_double **a, t_double **b);
void			rev_rotate_a(t_double **a, t_double **b);
void			rev_rotate_b(t_double **a, t_double **b);
void			rev_rotate_ab(t_double **a, t_double **b);
void			double_lstdel(t_double **a);
#endif
