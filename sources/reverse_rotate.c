/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:18:02 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/15 17:13:55 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		reverse(t_list **a, t_list **b, t_list **root_a, t_list **root_b)
{
	new_reverse(root_a);
	new_reverse(root_b);
	return (3);
}

int		new_reverse(t_list **stack)
{
	t_list	*prev;
	t_list	*buff;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return (3);
	buff = (*stack)->next;
	prev = (*stack);
	while (buff->next != NULL)
	{
		prev = prev->next;
		buff = buff->next;
	}
	prev->next = NULL;
	(*stack)->prev = buff;
	buff->next = (*stack);
	buff->prev = NULL;
	(*stack) = buff;
	return (3);
}
