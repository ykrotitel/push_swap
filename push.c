/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:39:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/17 20:06:57 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int     push_in_b(t_list **b, t_list **a, t_list **root_b, t_list **root_a)
{
	t_list *buff;
	t_list *buff_root;

	if ((*root_a) == (*a) && !(*a))
		return (2);
	if((*root_b) == NULL)
	{
		(*b) = malloc(sizeof(t_list));
		(*root_b) = (*b);
		(*b)->value = (*root_a)->value;
		(*b)->next = NULL;
		// (*b) = (*b)->next;
	}
	else
	{
		buff = malloc(sizeof(t_list));
		buff_root = buff;
		buff->value = (*root_a)->value;
		buff->next = (*root_b);
		(*root_b) = buff_root;
	}
	write (1, "push_in_b\n", 10);
	buff = (*root_a);
	(*root_a) = (*root_a)->next;
	while ((*a) != NULL && (*a)->next != NULL)
		(*a) = (*a)->next;
	if ((*root_b) == NULL)
		free(buff);
	if ((*root_a) == NULL)
		(*a) = (*root_a);
	return(2);
}

int     push_in_a(t_list **b, t_list **a, t_list **root_b, t_list **root_a)
{
	t_list *buff;
	t_list *buff_root;

	if ((*root_b) == (*b) && !(*b))
		return (2);
    if((*root_a) == NULL)	
	{
		(*a) = malloc(sizeof(t_list));
		(*a)->value = (*b)->value;
		(*a)->next = NULL;
	}
	else
	{
		buff = malloc(sizeof(t_list));
		buff_root = buff;
		buff->value = (*root_b)->value;
		buff->next = (*root_a);
		(*root_a) = buff_root;
	}
	buff = *(root_b);
	(*root_b) = (*root_b)->next;
		write (1, "push_in_a\n", 10);
	while ((*b) != NULL && (*b)->next != NULL)
		(*b) = (*b)->next;
	if ((*root_a) == NULL)
		free(buff);
	if ((*root_b) == NULL)
		(*b) = (*root_b);
	return (2);
}