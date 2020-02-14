/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:28:37 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/14 23:01:40 by acarlett         ###   ########.fr       */
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
	if ((*b) == (*root_b) && (*b) == NULL)
		return (0);
	check = malloc(sizeof(t_list));
	check = (*root_b)->next;
	if ((*root_b)->next == NULL || check == NULL)
		return (0);
	else
	{
		buff = malloc(sizeof(t_list));
		buff->value = (*root_b)->value;
		buff->next = NULL;
		buff2 = malloc(sizeof(t_list));
		buff2 = (*root_b)->next;
		(*root_b)->value = buff2->value;
		(*root_b) = (*root_b)->next;
		(*root_b)->value = buff->value;
	}
	(*root_b) = root;
	free(check);
	return (0);
}

int		swap_in_a(t_list **root_a, t_list **a)
{
	t_list *buff;
	t_list *buff2;
	t_list *root;
	t_list *check;

	root = (*root_a);
	check = NULL;
	if ((*a) == (*root_a) && (*a) == NULL)
		return (0);
	check = malloc(sizeof(t_list));
	check = (*root_a)->next;
	if ((*root_a)->next == NULL || check == NULL)
		return (0);
	else
	{
		buff = malloc(sizeof(t_list));
		buff->value = (*root_a)->value;
		buff->next = NULL;
		buff2 = malloc(sizeof(t_list));
		buff2 = (*root_a)->next;
		(*root_a)->value = buff2->value;
		(*root_a) = (*root_a)->next;
		(*root_a)->value = buff->value;
		free(buff);
		free(buff2);
	}
	(*root_a) = root;
	free(check);
	return (0);
}

int		swap(t_list **a, t_list **b, t_list **root_a, t_list **root_b)
{
	swap_in_a(root_a, a);
	swap_in_b(root_b, b);
	return (0);
}
