/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:24:13 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/14 13:44:50 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

static t_double	*create_node(char *elem, t_double **a, int pos, t_flags *flags)
{
	if (!(new = (*t_double)malloc(sizeof(t_double))))
	{
		print_err("malloc", flags);
		return (NULL);
	}
	new->elem = ft_atoi(elem);
	new->cur = pos;
	new->strd = 0;
	new->prio = 0;
	new->next = (*a) ? *a : NULL;
	new->prev = (*a) ? a->prev : NULL;
	(*a)->prev = new;
	return (new);
}

static int		stock_elem(char *elem, t_double **a, int pos, t_flags *flags)
{
	t_double	*tmp;
	t_double	*new;
	int			i;

	if (parse(elem) == -1)
		return (-1);
	if ((new = create_node(elem, a, pos, flags)) == NULL)
		return (-1);
	tmp = *a;
	i = 0;
	while (i < pos)
	{
		if (new->elem == tmp->elem)
		{
			print_err("duplicate", flags);
			return (-1);
		}
		i++;
		tmp = tmp->next;
	}
	return (1);
}

int				create_stack(int argc, char *argv[], t_double **a, t_flags *flags)
{
	int			i;

	i = flags->argc;
	while (i < argc)
	{
		if (stock_elem(argv[i], a, (i - flags->argc), flags) == -1)
		{
			if (*a)
				double_lstdel(a);
			return (-1)
		}
		i++;
	}
	return (1);
}
