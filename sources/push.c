/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:39:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/14 15:30:50 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		push_b(t_list **root_b, t_list **root_a)
{
	t_list	*root_buff;

	if (!(*root_a))
		return (2);
	if ((*root_b) == NULL)
	{
		(*root_b) = (*root_a);
		(*root_a) = (*root_a)->next;
		(*root_b)->next = NULL;
	}
	else
	{
		root_buff = (*root_b);
		(*root_b) = (*root_a);
		(*root_a) = (*root_a)->next;
		(*root_b)->next = root_buff;
	}
	return (2);
}

int		push_a(t_list **root_a, t_list **root_b)
{
	t_list	*root_buff;

	if (!(*root_b))
		return (2);
	if ((*root_a) == NULL)
	{
		(*root_a) = (*root_b);
		(*root_b) = (*root_b)->next;
		(*root_a)->next = NULL;
	}
	else
	{
		root_buff = (*root_a);
		(*root_a) = (*root_b);
		(*root_b) = (*root_b)->next;
		(*root_a)->next = root_buff;
	}
	return (2);
}

int		new_push(t_list **root_src, t_list **root_dest)
{
	t_list	*buff;

	if ((*root_src) == NULL)
		return (2);
	buff = (*root_src);
	if ((*root_src)->next != NULL)
	{
		(*root_src) = (*root_src)->next;
		(*root_src)->prev = NULL;
	}
	else
		(*root_src) = NULL;
		buff->next = (*root_dest);
		if ((*root_dest) != NULL)
			(*root_dest)->prev = buff;
		(*root_dest) = buff;
	return (2);
}
