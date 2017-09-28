/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chercher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:33:11 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/28 18:05:45 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char *argv[])
{
	t_double	**a = NULL;
	t_double	**b = NULL;
//	t_flags		flags;

	//init_flags(argc, argv, &flags);
	*a = NULL;
	*b = NULL;
	if (create_stack(argc, argv, a) == -1)
		return (0);
	exec_instruc(a, b);
	double_lstdel(a);
	double_lstdel(b);
	return (0);
}
