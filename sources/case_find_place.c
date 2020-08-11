/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_find_place.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:30:24 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/11 22:25:28 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int			CaseBiggerValue(t_list *root_b, int value, t_help *f)
{
	t_list	*buff;
	int		count;

	count = 0;
	buff = root_b;
	while ((buff->next != NULL) && (buff->value < value))
	{
		count++;
		buff = buff->next;
	}
	while ((buff->next != NULL) && (buff->value > value))
	{
		if (buff->value == f->max_b && buff->value > f->max_b)  /*!!!!!!!!!!!!!!!!!*/
			return (count);
		buff = buff->next;
		count++;
	}
	return (count);
}

int			CaseBiggerRoot(t_list *root_b, int value, t_help *f)
{
	t_list	*buff;
	int		count;

	count = 0;
	buff = root_b;
	while ((buff->next != NULL) && (buff->value > value))
	{
		if (buff->value == f->max_b && buff->value > f->max_b)
			return (count);
		count++;
		buff = buff->next;
	}
	return (count);
}