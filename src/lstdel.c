/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:52:05 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/28 15:06:11 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	double_lstdel(t_double **a)
{
	t_double	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	while (tmp->next != *a)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(tmp);
	a = NULL;
}

