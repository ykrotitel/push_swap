/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:39:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/15 17:08:32 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		new_push(t_list **root_src, t_list **root_dest)
{
	t_list	*buff;

	if ((*root_src) == NULL)
		return (2);
	buff = (*root_src);
	if ((*root_src)->next != NULL)
	{
		(*root_src) = (*root_src)->next;
		(*root_src)->prev = NULL;
	}
	else
		(*root_src) = NULL;
	buff->next = (*root_dest);
	if ((*root_dest) != NULL)
		(*root_dest)->prev = buff;
	(*root_dest) = buff;
	return (2);
}
