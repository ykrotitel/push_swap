/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:56:31 by acarlett          #+#    #+#             */
/*   Updated: 2020/03/02 20:22:07 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int		rotate_a(t_list **root_a)
{
	t_list *buff;
	t_list	*f;
	t_list 	*r;

	// write (1, "RT\n", 3);
	r = (*root_a);
	if (*(root_a) == NULL)
		return (0);
	f = (*root_a);
	buff = malloc(sizeof(t_list));
	buff->value = (*root_a)->value;
	while ((*root_a) != NULL)
	{
		(*root_a) = (*root_a)->next;
		if ((*root_a) == NULL)
			break;
		f->value = (*root_a)->value;
		f = f->next;
	}
	f->value = buff->value;
	(*root_a) = r;
	return(2);
}

int		rotate_b(t_list **root_b)
{
	t_list *buff;
	t_list	*f;
	t_list 	*r;

	r = (*root_b);
	if (*(root_b) == NULL)
		return (0);
	f = (*root_b);
	buff = malloc(sizeof(t_list));
	buff->value = (*root_b)->value;
	while ((*root_b) != NULL)
	{
		(*root_b) = (*root_b)->next;
		if ((*root_b) == NULL)
			break;
		f->value = (*root_b)->value;
		f = f->next;
	}
	f->value = buff->value;
	(*root_b) = r;
	return(2);
}

int		rotate(t_list **root_a, t_list **root_b)
{
	rotate_a(root_a);
	rotate_b(root_b);
	return (2);
}