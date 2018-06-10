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

/*
**	Use:	Stores the address of each instruction function into an void array.
*/

void		funp_init(void (**funp)())
{

	funp[PA] = push_a;
	funp[PB] = &push_b;
	funp[RA] = &rotate_a;
	funp[RRA] = &rev_rotate_a;
	funp[RB] = &rotate_b;
	funp[RRB] = &rev_rotate_b;
	funp[SA] = &swap_a;
	funp[SB] = &swap_b;
	funp[RR] = &rotate_ab;
	funp[RRR] = &rev_rotate_ab;
	funp[SS] = &swap_ab;
}

int		check_sorted(t_list *a)
{
	t_list		*tmp;
	int			len;
	int			ret;

	if (!a)
		return(ERROR);
	len = ft_lst2c_len(a) - 1;
	tmp = a;
	ret = SUCCESS;
	while (((t_elem*)(tmp->content))->nbr > ((t_elem*)(tmp->prev->content))->nbr)
		tmp = tmp->next;
	while (ret != ERROR && len--)
	{
		if (((t_elem*)(tmp->content))->nbr > ((t_elem*)(tmp->next->content))->nbr)
			ret = ERROR;
		tmp = tmp->next;
	}
	return (ret);
}

int		check_rev_sorted(t_list *a)
{
	t_list		*tmp;
	int			len;
	int			ret;

	if (!a)
		return(ERROR);
	len = ft_lst2c_len(a) - 1;
	tmp = a;
	ret = SUCCESS;
	while (ret != ERROR && len--)
	{
		if (((t_elem*)(tmp->content))->nbr < ((t_elem*)(tmp->next->content))->nbr)
			ret = ERROR;
		tmp = tmp->next;
	}
	return (ret);
}
