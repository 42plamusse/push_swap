/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:30:02 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/26 17:53:54 by plamusse         ###   ########.fr       */
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

# define ERROR			-1
# define SUCCESS		0
# define MALLOC_ERROR	NULL
# define A		1
# define B		2

/*
**	STRUCTURES
*/

typedef struct	s_elem
{
	int		nbr;
	int		pos;
	int		srtd;
	int		prio;
}		t_elem;

/*
**	ENUMS
*/

enum		instr
{
	PA,
	PB,
	RA,
	RRA,
	RB,
	RRB,
	SA,
	SB,
	RR,
	RRR,
	SS
};

/*
**	FUNCTIONS
*/

/*
**	utils.c
*/
void			funp_init(void (**funp)());
int			check_sorted(t_list *a);
int			check_rev_sorted(t_list *a);
/*
**	print.c
*/
void			ft_lst2c_print(t_list *lst);
void			ft_lst2c_print_rev(t_list *lst);
void			print_instr(int instr);

int			create_stack(int argc, char *argv[], t_list **a);
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
