/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 19:18:07 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/27 16:41:24 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
**	HEADERS
*/

# include "../../includes/list.h"
# include "../../includes/utils.h"

/*
**	STRUCTURES
*/

/*
**	Use:	Store the serie of instruction from the standard input.
*/

typedef struct s_instr	t_instr;
struct					s_instr;
{
	char	*content;
	t_instr	*next;
};

/*
**	Use:	Create an array that, after initialisation, will have every 
**			instructions linked to a function.
*/

typedef struct s_funp	t_funp;
struct					s_funp
{
	char	content[4];
	void	(*f)(t_double**, t_double**);
};

#endif
