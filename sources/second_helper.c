/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:27:36 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/09 20:18:30 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		display_error(int a)
{
	if (!a)
		ft_putstr("Error\n");
	else
		ft_putstr("Error  -->  Unreadble instruction\n");
	return (0);
}

int		check_massive(t_lst *root_a)
{
	int		i;
	t_lst	*buff;

	i = root_a->value;
	root_a = root_a->next;
	buff = root_a;
	while (buff != NULL)
	{
		while (root_a != NULL)
		{
			if (i == root_a->value && buff != NULL)
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

int		ft_check_data(t_list *root_a)
{
	t_list *buff;

	buff = root_a;
	root_a = root_a->next;
	while (root_a != NULL)
	{
		if (buff->value <= root_a->value)
		{
			buff = root_a;
			root_a = root_a->next;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
