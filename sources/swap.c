/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:28:37 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/20 14:56:59 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		swap_in_b(t_list **root_b, t_list **b)
{
	t_list *buff;
	t_list *buff2;
	t_list *root;
	t_list *check;

	root = (*root_b);
	check = NULL;
	if (((*b) == NULL || (*root_b) == NULL) && ((*b) == (*root_b)))
		return (2);
	if ((*root_b)->next)
		check = (*root_b)->next;
	else if (!((*root_b)->next) || ((*root_b)->next == NULL || check == NULL))
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
	return (swap_b_continue(root_b, root));
}

int		swap_b_continue(t_list **root_b, t_list *root)
{
	(*root_b) = root;
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
	return (swap_a_continue());
}

int		swap_a_continue(void)
{
	return (2);
}

int		swap(t_list **a, t_list **b, t_list **root_a, t_list **root_b)
{
	swap_in_a(root_a, a);
	swap_in_b(root_b, b);
	return (2);
}
