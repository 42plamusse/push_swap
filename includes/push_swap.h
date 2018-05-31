# include "utils.h"

# define ISMED 1
# define ISNOTMED 0
# define UNDER 1
# define OVER 0
typedef struct	s_opti
{
	int	ret_a;
	int	ret_b;
	int	size_stack;
	int	med_a;
	int	med_b;
	int	med_flag;
	int	cur;
	int	next;
	int	prev;
}		t_opti;

/*
**	Functions
*/

int	commit_instruction(t_list **a, t_list **b);
