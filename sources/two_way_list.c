/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_way_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:43:27 by acarlett          #+#    #+#             */
/*   Updated: 2020/09/09 19:30:45 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		twoway_list_if(t_list **a, t_list **root_a)
{
	(*a)->prev = NULL;
	(*root_a) = (*a);
}

void		twoway_list_else(t_list **a, t_list **prev)
{
	(*a)->prev = (*prev);
	(*prev)->next = (*a);
}

int			help_for_malloc(t_list **root_a)
{
	free_list1((*root_a));
	return (0);
}

int			maketwowaylist(t_lst *root_buff, t_help *f, int t)
{
	t_list	*a;
	t_list	*root_a;
	t_list	*prev;
	t_lst	*for_free;

	a = NULL;
	for_free = root_buff;
	root_a = NULL;
	while (root_buff != NULL)
	{
		if (!(a = malloc(sizeof(t_list))))
			return (help_for_malloc(&root_a));
		a->next = NULL;
		a->value = root_buff->value;
		if (root_a == NULL)
			twoway_list_if(&a, &root_a);
		else
			twoway_list_else(&a, &prev);
		prev = a;
		root_buff = root_buff->next;
	}
	a = NULL;
	free_list2(for_free);
	(t == 0 ? main_continue(root_a, f) : check_instruction(root_a, f));
	return (0);
}
