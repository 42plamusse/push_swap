/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:33:11 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/26 13:04:37 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char *argv[])
{
	int			i;
	t_double	**a;
	t_double	**b;
	t_flags		flags;

	//init_flags(argc, argv, &flags);
	if (create_stack(argc, argv, a, flags) == -1)
		return (0);
	exec_instruc(a, b);
	double_lstdel(a);
	double_lstdel(b);
	return (0);
}
