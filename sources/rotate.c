/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:56:31 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/31 16:37:11 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		rotate_a(t_list **root_a)
{
	t_list	*buff;
	t_list	*f;
	t_list	*r;

	r = (*root_a);
	if (*(root_a) == NULL)
	{
		return (1);
	}
	f = (*root_a);
	buff = malloc(sizeof(t_list));
	buff->value = (*root_a)->value;
	while ((*root_a) != NULL)
	{
		(*root_a) = (*root_a)->next;
		if ((*root_a) == NULL)
			break ;
		f->value = (*root_a)->value;
		f = f->next;
	}
	f->value = buff->value;
	(*root_a) = r;
	free(buff);
	return (2);
}

int		rotate_b(t_list **root_b)
{
	t_list	*buff;
	t_list	*f;
	t_list	*r;

	r = (*root_b);
	if (*(root_b) == NULL)
		return (1);
	f = (*root_b);
	buff = malloc(sizeof(t_list));
	buff->value = (*root_b)->value;
	while ((*root_b) != NULL)
	{
		(*root_b) = (*root_b)->next;
		if ((*root_b) == NULL)
			break ;
		f->value = (*root_b)->value;
		f = f->next;
	}
	f->value = buff->value;
	(*root_b) = r;
	free(buff);
	return (2);
}

int		rotate(t_list **root_a, t_list **root_b)
{
	rotate_a(root_a);
	rotate_b(root_b);
	return (2);
}
