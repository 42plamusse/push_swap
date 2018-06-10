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

void	set_rot(t_rot *rot, int i)
{
	if (i == 0)
		ra_rrb(rot);
	if (i == 1)
		rb_rra(rot);
	if (i == 2)
		rr(rot);
	if (i == 3)
		rrr(rot);
}
