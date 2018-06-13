# include "utils.h"

# define ISMED 1
# define ISNOTMED 0
# define UNDER 1
# define OVER 0

typedef struct	s_rot
{
	int	best;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
}		t_rot;

typedef struct	s_opti
{
	t_rot	rot;
	int	stack;
	int	size_a;
	int	size_b;
	int	max;
	int	cur;
	int	next;
	int	prev;
}		t_opti;

/*
**	Functions
*/

int	commit_instruction(t_list **a, t_list **b);
void	set_rot(t_rot *rot, int i);
void	get_elem_max(t_list *b, t_opti *op);
void	push_back(t_list **a, t_list **b, t_opti *op);
