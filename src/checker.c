/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chercher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:33:11 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/29 19:46:13 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


int		main(int argc, char *argv[])
{
	t_double	**a;
	t_double	**b = NULL;
//	t_flags		flags;

	a = (t_double**)malloc(sizeof(t_double*));
	//init_flags(argc, argv, &flags);
	if (create_stack(argc, argv, a) == -1)
		return (0);
	exec_instruc(a, b);
	double_lstdel(a);
	double_lstdel(b);
	return (0);
}
