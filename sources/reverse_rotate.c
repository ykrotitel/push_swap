/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:18:02 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/29 18:26:39 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		reverse_a(t_list **a, t_list **root_a, int t)
{
	t_list	*buff;
	t_list	*tmp;

	if ((*root_a) == NULL || (*root_a)->next == NULL)
		return (1);
	buff = (*root_a);
	tmp = (*root_a)->next;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		buff = buff->next;
	}
	tmp->next = (*root_a);
	(*root_a) = tmp;
	buff->next = NULL;
	(*a) = buff;
	return (t ? 1 : 3);
}

int		reverse_b(t_list **b, t_list **root_b, int t)
{
	t_list	*buff;

	buff = (*root_b);
	if ((*root_b) == NULL)
		return (1);
	while (buff != (*b))
	{
		if (buff->next == (*b))
			break ;
		buff = buff->next;
	}
	buff->next = NULL;
	(*b)->next = (*root_b);
	(*root_b) = (*b);
	while ((*b)->next != NULL)
		(*b) = (*b)->next;
	return (t ? 2 : 3);
}

int		reverse(t_list **a, t_list **b, t_list **root_a, t_list **root_b)
{
	reverse_a(a, root_a, 1);
	reverse_a(b, root_b, 1);
	return (3);
}
