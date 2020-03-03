/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:28:37 by acarlett          #+#    #+#             */
/*   Updated: 2020/03/03 19:24:14 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int		swap_in_b(t_list **root_b, t_list **b)
{
	t_list *buff;
	t_list *buff2;
	t_list *root;
	t_list *check;

	root = (*root_b);
	check = NULL;
	// write (1, "swap_in_b\n", 10);
	if (((*b) == NULL || (*root_b) == NULL) && ((*b) == (*root_b)))
		return (2);
	if ((*root_b)->next)
		check = (*root_b)->next;
	else
		return (2);
	// write (1, "RT\n", 3);
	if ((*root_b)->next == NULL || check == NULL)
		return (2);
	else
	{
		buff = malloc(sizeof(t_list));
		buff->value = (*root_b)->value;
		buff->next = NULL;
		buff2 = (*root_b)->next;
		(*root_b)->value = buff2->value;
		(*root_b) = (*root_b)->next;
		(*root_b)->value = buff->value;
		free(buff);
	}
	(*root_b) = root;
	ft_putstr("sb\n");
	return (2);
}

int		swap_in_a(t_list **root_a, t_list **a)
{
	t_list *buff;
	t_list *buff2;
	t_list *root;
	t_list *check;

	root = (*root_a);
	check = NULL;
	// write (1, "swap_in_a\n", 10);
	if ((*a) == (*root_a) && (*a) == NULL)
		return (2);
	check = (*root_a)->next;
	if ((*root_a)->next == NULL || check == NULL)
		return (2);
	else
	{
		buff = malloc(sizeof(t_list));
		buff->value = (*root_a)->value;
		buff->next = NULL;
		buff2 = (*root_a)->next;
		(*root_a)->value = buff2->value;
		(*root_a) = (*root_a)->next;
		(*root_a)->value = buff->value;
		free(buff);
	}
	(*root_a) = root;
	ft_putstr("sa\n");
	return (2);
}

int		swap(t_list **a, t_list **b, t_list **root_a, t_list **root_b)
{
	swap_in_a(root_a, a);
	swap_in_b(root_b, b);
	return (2);
}
