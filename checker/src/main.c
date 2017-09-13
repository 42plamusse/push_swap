/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:33:11 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/13 03:09:12 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char *argv[])
{
	int			i;
	t_double	**a;
	t_double	**b;

	if (parser(argc, argv, a, b) == -1)
		return (0);
	exec_instruc(a, b);
	double_lstdel(a);
	double_lstdel(b);
	return (0);
}
