/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:05:38 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/26 17:00:17 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char *argv[])
{
	t_list		*a = NULL;
	t_list		*b = NULL;
	//	t_flags		flags;

	//init_flags(argc, argv, &flags);
	if (create_stack(argc, argv, &a) == SUCCESS)
	{
		ft_lst2c_print(a);
		exec_instruc(&a, &b);
	}
	ft_lst2c_del(&a, &ft_lst_memclr);
	ft_lst2c_del(&b, &ft_lst_memclr);
	return (0);
}
