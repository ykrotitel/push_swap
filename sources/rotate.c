/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:56:31 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/15 17:14:15 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		rotate(t_list **root_a, t_list **root_b)
{
	new_rotate(root_a);
	new_rotate(root_b);
	return (2);
}

int		new_rotate(t_list **stack)
{
	t_list	*buff;
	t_list	*s_buff;

	buff = (*stack);
	s_buff = buff;
	if ((*stack) == NULL || (*stack)->next == NULL)
		return (2);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	while (s_buff->next != NULL)
		s_buff = s_buff->next;
	s_buff->next = buff;
	buff->prev = s_buff;
	buff->next = NULL;
	return (2);
}
