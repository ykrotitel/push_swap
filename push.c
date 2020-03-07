/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:39:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/03/07 22:08:56 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int     push_in_b(t_list **b, t_list **a, t_list **root_b, t_list **root_a)
{
	t_list *buff;
	t_list *buff_root;

	// if ((*root_a) == (*a) && !(*a))
	// 	return (2);
	if((*root_b) == NULL)
	{
		(*b) = malloc(sizeof(t_list));
		(*root_b) = (*b);
		(*b)->value = (*root_a)->value;
		(*b)->next = NULL;
	}
	else
	{
		buff = malloc(sizeof(t_list));
		buff_root = buff;
		buff->value = (*root_a)->value;
		buff->next = (*root_b);
		(*root_b) = buff_root;
	}
	buff = (*root_a);
	(*root_a) = (*root_a)->next;
	while ((*a) != NULL && (*a)->next != NULL)
		(*a) = (*a)->next;
	if ((*root_b) == NULL)
		free(buff);
	if ((*root_a) == NULL)
		(*a) = (*root_a);
	ft_putstr("pa\n");
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
	while ((*b) != NULL && (*b)->next != NULL)
		(*b) = (*b)->next;
	if ((*root_a) == NULL)
		free(buff);
	if ((*root_b) == NULL)
		(*b) = (*root_b);
		ft_putstr("pb\n");
	return (2);
}

int     push_for_push_swap(t_list **b, t_list **a, t_list **root_b, t_list **root_a)
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
	while ((*b) != NULL && (*b)->next != NULL)
		(*b) = (*b)->next;
	if ((*root_a) == NULL)
		free(buff);
	if ((*root_b) == NULL)
		(*b) = (*root_b);
		ft_putstr("pa\n");
	return (2);
}

int		push_b(t_list **root_b, t_list **root_a)
{
	t_list *buff;
	t_list *root_buff;

	if ((*root_b) == NULL)
	{
		write (1, "RR", 2);
		(*root_b) = malloc(sizeof(t_list));
		(*root_b)->next = NULL;
	}
	(*root_a)->next = (*root_b);
	(*root_b) = (*root_a);
	(*root_a) = (*root_a)->next;
	ft_putstr("pb\n");
	return (2);
}

int		push_a(t_list **root_a, t_list **root_b)
{
	t_list *buff;
	t_list *root_buff;

	if ((*root_a) == NULL)
	{
		(*root_a) = malloc(sizeof(t_list));
		(*root_a)->next = NULL;
	}
	(*root_b)->next = (*root_a);
	(*root_a) = (*root_b);
	(*root_b) = (*root_b)->next;
	ft_putstr("pa\n");
	return (2);
}