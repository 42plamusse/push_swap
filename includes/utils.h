/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:30:02 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/24 21:21:17 by plamusse         ###   ########.fr       */
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
**	DEFINES
*/

# define ERROR		-1
# define SUCCESS	0

/*
**	STRUCTURES
*/

/*
**	FUNCTIONS
*/

int				create_stack(int argc, char *argv[], t_list *a);
void			push_a(t_list **a, t_list **b);
void			push_b(t_list **a, t_list **b);
void			swap_a(t_list **a, t_list **b);
void			swap_b(t_list **a, t_list **b);
void			swap_ab(t_list **a, t_list **b);
void			rotate_a(t_list **a, t_list **b);
void			rotate_b(t_list **a, t_list **b);
void			rotate_ab(t_list **a, t_list **b);
void			rev_rotate_a(t_list **a, t_list **b);
void			rev_rotate_b(t_list **a, t_list **b);
void			rev_rotate_ab(t_list **a, t_list **b);
#endif
