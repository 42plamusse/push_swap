/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:24:13 by plamusse          #+#    #+#             */
/*   Updated: 2018/06/14 15:47:06 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int		parse_int(char *elem)
{
	long long	tmp;
	int			i;
	int			sign;

	if (ft_strlen(elem) > 11)
		return (ERROR);
	i = 0;
	sign = 1;
	if (elem[i] == '-')
	{
		sign = -1;
		i++;
	}
	tmp = 0;
	while (elem[i] && ft_isdigit(elem[i]))
		tmp = tmp * 10 + (elem[i++] - '0');
	if (elem[i] || (tmp > 2147483647 && sign > 0) ||
					(tmp > 2147483648 && sign < 0))
		return (ERROR);
	return (SUCCESS);
}

static void		init_elem(t_elem *elem, char *nbr, int pos)
{
	elem->nbr = ft_atoi(nbr);
	elem->pos = pos;
	elem->srtd = 0;
	elem->prio = 0;
}

static t_list	*create_node(char *nbr, t_list **a, int pos)
{
	t_elem		elem;
	t_list		*new;

	init_elem(&elem, nbr, pos);
	new = ft_lst2c_push_back(a, ft_lstnew(&elem, sizeof(elem)));
	return (new);
}

static int		stock_elem(char *elem, t_list **a, int pos)
{
	t_list		*tmp;
	t_list		*new;
	int			i;

	if (parse_int(elem) == ERROR)
		return (ERROR);
	if ((new = create_node(elem, a, pos)) == MALLOC_ERROR)
		return (ERROR);
	tmp = *a;
	i = 1;
	while (i < pos)
	{
		if (((t_elem*)(new->content))->nbr == ((t_elem*)(tmp->content))->nbr)
			return (ERROR);
		i++;
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int				create_stack(int argc, char *argv[], t_list **a)
{
	int			i;
	char		**tab;
	int			size;

	tab = &argv[1];
	size = argc - 1;
	if (argc == 2)
	{
		tab = ft_strsplit(argv[1], ' ');
		size = ft_tablen((const char **)tab);
	}
	i = 0;
	while (i < size)
	{
		if (stock_elem(tab[i], a, i + 1) == ERROR)
			return (ERROR);
		i++;
	}
	if (argc == 2)
		ft_tabclr(tab);
	return (SUCCESS);
}
