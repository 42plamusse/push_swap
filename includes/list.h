/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:47:46 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/14 10:09:06 by plamusse         ###   ########.fr       */
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
	int			asize;
	int			bsize;
	t_double	*next;
	t_double	*prev;
};

#endif
