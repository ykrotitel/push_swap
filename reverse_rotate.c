/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:18:02 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/17 17:29:17 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int		reverse_a(t_list **a, t_list **root_a)
{
	t_list	*buff;
	t_list *e;
	t_list *r;
	t_list *t;

	
	buff = (*root_a);
	e = (*root_a)->next;
	r = e->next;
	t = r->next;
	while (buff != (*a))
	{
		if (buff->next == (*a))
			break;
		buff = buff->next;
	}
	buff->next = NULL;
	(*a)->next = (*root_a);
	write (1, "reverse_a\n", 10);	
	(*root_a) = (*a);
	while ((*a)->next != NULL)
		(*a) = (*a)->next;
	return (3);
}

int		reverse_b(t_list **b, t_list **root_b)
{
	t_list	*buff;

	buff = (*root_b);
	write (1, "reverse_b\n", 10);	
	while (buff != (*b))
	{
		if (buff->next == (*b))
			break;
		buff = buff->next;
	}
	buff->next = NULL;
	(*b)->next = (*root_b);
	(*root_b) = (*b);
	while ((*b)->next != NULL)
		(*b) = (*b)->next;
	return (3);
}

int		reverse(t_list **a, t_list **b, t_list **root_a, t_list **root_b)
{
	reverse_a(a, root_a);
	reverse_b(b, root_b);
	return (3);
}