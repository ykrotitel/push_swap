/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_find_place.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:30:24 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/13 06:45:49 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int			CaseBiggerValue(t_list *root_b, int value, t_help *f)
{
	t_list	*buff;
	int		count;

	count = 0;
	buff = root_b;
	if (root_b->value == f->max_b)
		return (0);
	while ((buff->next != NULL) && (buff->value < value))
	{
		count++;
		buff = buff->next;
		if (buff->value == f->max_b)
			break ;
	}
	if (buff->value < value)
		return (count);
	while ((buff->next != NULL) && (buff->value > value))
	{
		buff = buff->next;
		count++;
	}
	if (buff->next == NULL && buff->value > value)
		count++;
	return (count);
}

int			CaseBiggerRoot(t_list *root_b, int value, t_help *f)
{
	t_list	*buff;
	int		count;

	count = 0;
	buff = root_b;
	if (root_b->value == f->max_b && value < f->min_b)
	{
		return (0);
	}
	while ((buff->next != NULL) && (buff->value > value))
	{
		if (buff->value == f->min_b)
			break ;
		count++;
		buff = buff->next;
	}
	if (value < buff->value)
		return (count);
	while ((buff->next != NULL) && buff->value > value)
	{
		count++;
		buff = buff->next;
	}
	return (count);
}