/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:36:33 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/13 15:37:30 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr(t_rot *rot)
{
	rot->rrr = 0;
	rot->rra = 0;
	rot->rrb = 0;
	if (rot->ra >= rot->rb)
	{
		rot->rr = rot->rb;
		rot->ra = rot->ra - rot->rb;
		rot->rb = 0;
	}
	else
	{
		rot->rr = rot->ra;
		rot->rb = rot->rb - rot->ra;
		rot->ra = 0;
	}
}

static void	rrr(t_rot *rot)
{
	rot->rr = 0;
	rot->ra = 0;
	rot->rb = 0;
	if (rot->rra >= rot->rrb)
	{
		rot->rrr = rot->rrb;
		rot->rra = rot->rra - rot->rrb;
		rot->rrb = 0;
	}
	else
	{
		rot->rrr = rot->rra;
		rot->rrb = rot->rrb - rot->rra;
		rot->rra = 0;
	}
}

static void	rb_rra(t_rot *rot)
{
	rot->ra = 0;
	rot->rrb = 0;
	rot->rr = 0;
	rot->rrr = 0;
}

static void	ra_rrb(t_rot *rot)
{
	rot->rb = 0;
	rot->rra = 0;
	rot->rr = 0;
	rot->rrr = 0;
}

void		set_rot(t_rot *rot, int tab[4])
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	rot->best = tab[i];
	while (i < 4)
	{
		if (tab[i] < rot->best)
		{
			rot->best = tab[i];
			ret = i;
		}
		i++;
	}
	if (ret == 0)
		ra_rrb(rot);
	else if (ret == 1)
		rb_rra(rot);
	else if (ret == 2)
		rr(rot);
	else if (ret == 3)
		rrr(rot);
}
