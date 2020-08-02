/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:07:53 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/02 16:50:19 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int			check_line(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0')
		return (0);
	return (1);
}

void		right_sort_3(t_list *buff, t_list **root_a, t_list **a, t_help *f)
{
	t_list *buff1;

	buff1 = buff->next;
	if (((*root_a)->value > buff->value && buff->value > buff1->value) ||
	((*root_a)->value > buff1->value && buff1->value > buff->value))
		rotate_a(root_a) && write(1, "ra\n", 3);
	buff = (*root_a)->next;
	buff1 = buff->next;
	if ((buff1->value > (*root_a)->value && (*root_a)->value > buff->value) ||
	(buff->value > buff1->value && buff1->value > (*root_a)->value) ||
	(buff1->value > (*root_a)->value && (*root_a)->value > buff->value))
		swap_in_a(root_a, a) && write(1, "sa\n", 3);
	buff = (*root_a)->next;
	buff1 = buff->next;
	if (buff->value > (*root_a)->value && (*root_a)->value > buff1->value)
		reverse_a(a, root_a, 0) && write(1, "rra\n", 4);
	buff = (*root_a)->next;
	buff1 = buff->next;
	if (buff1->value > buff->value && buff->value > (*root_a)->value)
		return ;
	right_sort_3(buff, root_a, a, f);
}

void		sort_only_2_3(t_list **root_a, t_list **a, t_help *f)
{
	t_list	*buff;

	buff = (*root_a)->next;
	if (f->size == 2)
	{
		if (buff->value < (*root_a)->value)
			swap_in_a(root_a, a) && write(1, "sa\n", 3);
	}
	else
		right_sort_3(buff, root_a, a, f);
}
