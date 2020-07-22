/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:57:05 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/20 16:45:43 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		check_rra(t_list **a, t_list **root_a)
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
	return (1);
}

int		check_rrb(t_list **b, t_list **root_b)
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
	return (1);
}

int		check_ra(t_list *root_a)
{
	t_list	*buff;
	t_list	*f;
	t_list	*r;

	r = root_a;
	if (root_a == NULL)
		return (0);
	f = root_a;
	buff = malloc(sizeof(t_list));
	buff->value = root_a->value;
	while (root_a != NULL)
	{
		root_a = root_a->next;
		if (root_a == NULL)
			break ;
		f->value = root_a->value;
		f = f->next;
	}
	f->value = buff->value;
	root_a = r;
	return (1);
}

int		check_rb(t_list **root_b)
{
	t_list	*buff;
	t_list	*f;
	t_list	*r;

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
			break ;
		f->value = (*root_b)->value;
		f = f->next;
	}
	f->value = buff->value;
	(*root_b) = r;
	return (1);
}

int		check_argv(char *s)
{
	int i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}
