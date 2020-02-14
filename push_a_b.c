/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:39:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/14 22:36:36 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int     push_in_b(t_list **b, t_list **a, t_list **root_b, t_list **root_a)
{
	t_list *buff;
	t_list *buff_root;

	if ((*root_a) == (*a) && !(*a))
		return (0);
	if((*root_b) == NULL)
	{
		write (1, "F_B\n", 4);
		(*b) = malloc(sizeof(t_list));
		(*root_b) = (*b);
		(*b)->value = (*root_a)->value;
		(*b)->next = NULL;
		(*b) = (*b)->next;
	}
	else
	{
		write (1, "S_B\n", 4);
		buff = malloc(sizeof(t_list));
		buff_root = buff;
		buff->value = (*root_a)->value;
		buff->next = (*root_b);
		(*root_b) = buff_root;
	}
	buff = (*root_a);
	(*root_a) = (*root_a)->next;
	free(buff);
	(*a) = NULL;
	return(1);
}

int     push_in_a(t_list **b, t_list **a, t_list **root_b, t_list **root_a)
{
	t_list *buff;
	t_list *buff_root;

	if ((*root_b) == (*b) && !(*b))
		return (0);
    if((*root_a) == NULL)	
	{
		write (1, "F_A\n", 4);
		(*a) = malloc(sizeof(t_list));
		(*a)->value = (*b)->value;
		(*a)->next = NULL;
		(*a) = (*a)->next;
	}
	else
	{
		write (1, "S_A\n", 4);
		buff = malloc(sizeof(t_list));
		buff_root = buff;
		buff->value = (*root_b)->value;
		buff->next = (*root_a);
		(*root_a) = buff_root;
	}
	buff = *(root_b);
	(*root_b) = (*root_b)->next;
	free(buff);
	(*b) = NULL;
	return (1);
}