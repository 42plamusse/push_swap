/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 20:47:18 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/13 16:54:58 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_list		*a;
	t_list		*b;

	if (argc >= 2 && create_stack(argc, argv, &a) == SUCCESS)
		commit_instruction(&a, &b);
	else
		ft_printf("Error\n");
	ft_lst2c_del(&a, &ft_lst_memclr);
	ft_lst2c_del(&b, &ft_lst_memclr);
	return (0);
}
