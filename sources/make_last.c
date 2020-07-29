/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:10:49 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/29 20:37:26 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		second_step_while(t_help **f, t_list **root_a,
t_list **a, t_list **root_b)
{
	t_list	*buff;

	buff = (*root_a);
	while (buff != NULL)
	{
		if (buff->value > (*f)->min && buff->value < (*f)->mid)
		{
			(*f)->ccc = buff->value;
			(*f)->q = help_rotate((*root_a), (*f)->ccc);
			(*f)->w = (*f)->cc - (*f)->q;
			while ((*root_a)->value != (*f)->ccc)
				((*f)->w < (*f)->q ? reverse_a(a, root_a, 0) &&
			write(1, "rra\n", 4) : rotate_a(root_a) && write(1, "ra\n", 3));
			buff = (*root_a);
			(*f)->c = 0;
			push_b(root_b, root_a) && write(1, "pb\n", 3);
		}
		else
		{
			buff = buff->next;
			(*f)->c++;
			continue ;
		}
		buff = (*root_a);
	}
}

void		second_step_secondwhile(t_help **f, t_list **root_a,
t_list **root_b, t_list **a)
{
	t_list	*buff;
	int		c;

	buff = (*root_a);
	while (buff != NULL)
	{
		if (buff->value > (*f)->mid && buff->value < (*f)->max)
		{
			c = buff->value;
			while ((*root_a)->value != c)
			{
				(*f)->ccc = buff->value;
				(*f)->q = help_rotate((*root_a), (*f)->ccc);
				(*f)->w = (*f)->cc - (*f)->q;
				while ((*root_a)->value != (*f)->ccc)
					((*f)->w > (*f)->q ? reverse_a(a, root_a, 0) &&
				write(1, "rra\n", 4) : rotate_a(root_a) && write(1, "ra\n", 3));
			}
			buff = (*root_a);
			push_b(root_b, root_a) && write(1, "pb\n", 3);
		}
		else
		{
			buff = buff->next;
			(*f)->cc++;
			continue;
		}
		buff = (*root_a);
	}
}
