/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:28:10 by plamusse          #+#    #+#             */
/*   Updated: 2018/04/26 17:54:52 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lst2c_print_rev(t_list *lst)
{
	t_list		*tmp;
	t_elem		*elem;
	int			len;

	if (!lst)
		return ;
	len = ft_lst2c_len(lst) + 1;
	tmp = lst;
	while (len--)
	{
		elem = (t_elem*)tmp->content;
		ft_printf("%d", elem->nbr);
		if (len)
			ft_printf("-");
		else
			ft_printf("\n");
		tmp = tmp->prev;
	}
}

void	ft_lst2c_print(t_list *lst)
{
	t_list		*tmp;
	t_elem		*elem;
	int			len;

	if (!lst)
		return ;
	len = ft_lst2c_len(lst) + 1;
	tmp = lst;
	while (len--)
	{
		elem = (t_elem*)tmp->content;
		ft_printf("%d", elem->nbr);
		if (len)
			ft_printf("-");
		else
			ft_printf("\n");
		tmp = tmp->next;
	}
}
