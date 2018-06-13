/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:05:38 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/13 16:51:28 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char *argv[])
{
	t_list		*a;
	t_list		*b;

	if (argc >= 2 && create_stack(argc, argv, &a) == SUCCESS)
		exec_instruc(&a, &b);
	else
		ft_printf("Error\n");
	ft_lst2c_del(&a, &ft_lst_memclr);
	ft_lst2c_del(&b, &ft_lst_memclr);
	return (0);
}
