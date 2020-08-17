/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:28:37 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/15 17:35:50 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		swap(t_list **root_a, t_list **root_b)
{
	new_swap(root_a);
	new_swap(root_b);
	return (2);
}

int		new_swap(t_list **stack)
{
	t_list	*buff;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return (2);
	buff = (*stack)->next;
	buff->prev = NULL;
	(*stack)->next = buff->next;
	buff->next = (*stack);
	(*stack)->prev = buff;
	(*stack) = buff;
	return (2);
}
