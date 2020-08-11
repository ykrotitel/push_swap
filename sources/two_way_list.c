/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_way_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:43:27 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/11 19:04:43 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"


int		MakeTwoWayList(t_lst *root_buff, t_help *f, int t)
{
	t_list	*a;
	t_list	*root_a;
	t_list	*prev;

	a = NULL;
	root_a = NULL;
	while (root_buff != NULL)
	{
		a = malloc(sizeof(t_list));
		a->next = NULL;
		a->value = root_buff->value;
		if (root_a == NULL)
		{
			a->prev = NULL;
			root_a = a;
		}
		else
		{
			a->prev = prev;
			prev->next = a;
		}
		prev = a;
		root_buff = root_buff->next;
	}
	return (t == 0 ? main_continue(a, root_a, f) : check_instruction(a, root_a));
}