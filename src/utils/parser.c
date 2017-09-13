/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:24:13 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/10 20:23:12 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"

int		lst_parser(int argc, char *argv[], t_dobl **lst)
{
	if ((!check_elem_lst(argc, argv)) || (!create_lst(argc, argv, lst)))
		return (0);
	sort_lst(lst);
	return (1);
}
