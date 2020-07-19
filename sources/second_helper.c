/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:27:36 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/19 20:25:55 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		display_error(void)
{
	ft_putstr("Error1\n");
	return (0);
}

int		check_massive(t_list *root_a)
{
	int		i;
	t_list	*buff;

	i = root_a->value;
	root_a = root_a->next;
	buff = root_a;
	while (buff != NULL)
	{
		while (root_a != NULL)
		{
			if (i == root_a->value)
				return (0);
			root_a = root_a->next;
		}
		i = buff->value;
		buff = buff->next;
		root_a = buff;
	}
	return (1);
}

int		check_stack_a(t_list *root_a)
{
	t_list *buff;

	buff = root_a->next;
	while (buff != NULL)
	{
		if (root_a->value > buff->value)
			return (1);
		buff = buff->next;
		root_a = root_a->next;
	}
	return (0);
}