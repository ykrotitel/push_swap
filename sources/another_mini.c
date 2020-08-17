/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:07:53 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/15 18:44:43 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int			another_check(t_lst *root_a, t_help *f)
{
	if (root_a == NULL)
	{
		free(f);
		return (0);
	}
	if (!(is_overint(root_a)) || !(check_massive(root_a)))
	{
		free(f);
		free_list2(root_a);
		return (display_error(0));
	}
	maketwowaylist(root_a, f, 1);
	return (0);
}

void		right_sort_3(t_list *buff, t_list **root_a, t_help *f)
{
	t_list *buff1;

	buff1 = buff->next;
	if (((*root_a)->value > buff->value && buff->value > buff1->value) ||
	((*root_a)->value > buff1->value && buff1->value > buff->value))
		new_rotate(root_a) && write(1, "ra\n", 3);
	buff = (*root_a)->next;
	buff1 = buff->next;
	if ((buff1->value > (*root_a)->value && (*root_a)->value > buff->value) ||
	(buff->value > buff1->value && buff1->value > (*root_a)->value) ||
	(buff1->value > (*root_a)->value && (*root_a)->value > buff->value))
		new_swap(root_a) && write(1, "sa\n", 3);
	buff = (*root_a)->next;
	buff1 = buff->next;
	if (buff->value > (*root_a)->value && (*root_a)->value > buff1->value)
		new_reverse(root_a) && write(1, "rra\n", 4);
	buff = (*root_a)->next;
	buff1 = buff->next;
	if (buff1->value > buff->value && buff->value > (*root_a)->value)
		return ;
	right_sort_3(buff, root_a, f);
}

void		help_for_sort_4_5(t_list **root_a, t_help **f)
{
	takeminmaxvalue((*root_a), f);
	(*f)->up = takenumberoperationup((*root_a), (*f)->min, (*f)->min);
	(*f)->down = takenumberoperationdown((*root_a), (*f)->min, (*f)->min);
	if ((*f)->up <= (*f)->down)
		while ((*root_a)->value != (*f)->min)
			new_rotate(root_a) && write(1, "ra\n", 3);
	else
		while ((*root_a)->value != (*f)->min)
			new_reverse(root_a) && write(1, "rra\n", 4);
}

void		sort_4_5(t_list **root_a, t_help *f)
{
	t_list	*root_b;

	root_b = NULL;
	help_for_sort_4_5(root_a, &f);
	new_push(root_a, &root_b) && write(1, "pb\n", 3);
	help_for_sort_4_5(root_a, &f);
	new_push(root_a, &root_b) && write(1, "pb\n", 3);
	f->size -= 2;
	sort_only_2_3_5(root_a, f);
	new_push(&root_b, root_a) && write(1, "pa\n", 3);
	new_push(&root_b, root_a) && write(1, "pa\n", 3);
}

void		sort_only_2_3_5(t_list **root_a, t_help *f)
{
	t_list	*buff;

	buff = (*root_a)->next;
	if (f->size == 2)
	{
		if (buff->value < (*root_a)->value)
			new_swap(root_a) && write(1, "sa\n", 3);
	}
	else if (f->size == 3)
		right_sort_3(buff, root_a, f);
	else if (f->size == 4 || f->size == 5)
		sort_4_5(root_a, f);
}
