/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:39:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/17 19:47:05 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		push_b(t_list **root_b, t_list **root_a)
{
	t_help	p;
	t_list	*root_buff;

	if ((*root_b) == NULL)
	{
		(*root_b) = (*root_a);
		(*root_a) = (*root_a)->next;
		(*root_b)->next = NULL;
	}
	else
	{
		root_buff = (*root_b);
		(*root_b) = (*root_a);
		(*root_a) = (*root_a)->next;
		(*root_b)->next = root_buff;
	}
	ft_putstr("pb\n");
	return (2);
}

int		push_a(t_list **root_a, t_list **root_b)
{
	t_list *root_buff;

	if ((*root_a) == NULL)
	{
		(*root_a) = (*root_b);
		(*root_b) = (*root_b)->next;
		(*root_a)->next = NULL;
	}
	else
	{
		root_buff = (*root_a);
		(*root_a) = (*root_b);
		(*root_b) = (*root_b)->next;
		(*root_a)->next = root_buff;
	}
	ft_putstr("pa\n");
	return (2);
}
