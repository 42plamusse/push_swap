# include "utils.h"

# define ISMED 1
# define ISNOTMED 0
typedef struct	s_opti
{
	int	ret_a;
	int	ret_b;
	int	size_stack;
	int	med;
	int	ismed_cur;
	int	ismed_next;
}		t_opti;

/*
**	Functions
*/

int	commit_instruction(t_list **a, t_list **b);
