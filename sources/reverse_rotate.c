/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:18:02 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/17 15:00:51 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		reverse_a(t_list **a, t_list **root_a)
{
	t_list	*buff;
	t_list	*tmp;

	buff = (*root_a);
	tmp = (*root_a)->next;
	while (tmp->next != NULL)
	{
		buff = buff->next;
		tmp = tmp->next;
	}
	tmp->next = (*root_a);
	buff->next = NULL;
	(*root_a) = tmp;
	(*a) = (*root_a);
	while ((*a)->next != NULL)
		(*a) = (*a)->next;
	ft_putstr("rra\n");
	return (3);
}

int		reverse_b(t_list **b, t_list **root_b)
{
	t_list	*buff;

	buff = (*root_b);
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
	ft_putstr("rrb\n");
	return (3);
}

int		reverse(t_list **a, t_list **b, t_list **root_a, t_list **root_b)
{
	reverse_a(a, root_a);
	reverse_b(b, root_b);
	return (3);
}
