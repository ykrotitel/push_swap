/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_number_operation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:17:56 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/10 20:50:01 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		TakeNumberOperationUp(t_list *root_a, int min, int max)
{
	t_list	*buff;
	int		i;

	buff = root_a;
	i = 0;
	while (buff->next != NULL)
	{
		if (buff->value >= min && buff->value <= max)
			return (i);
		buff = buff->next;
		i++;
	}
	return(i);
}

int			TakeNumberOperationDown(t_list *root_a, int min, int max)
{
	t_list	*buff;
	int		i;
	int		s;

	i = 0;
	buff = root_a;
	while (buff->next != NULL)
		buff = buff->next;
	while (buff != NULL)
	{
		if (buff->value >= min && buff->value <= max)
			return (i);
		i++;
		buff = buff->prev;
	}
	return (i);
}

int			TakeNumberOperationUpB(t_list *root_b, int value, t_help *f)
{
	if (value > root_b->value)
		return (CaseBiggerValue(root_b, value, f));
	return (CaseBiggerRoot(root_b, value, f));
}

int			TakeNumberOperationDownB(t_list *root_b, int value, t_help *f)
{
	int		i;
	int		size;
	t_list	*buff;

	buff = root_b;
	size = 0;
	i = TakeNumberOperationUpB(root_b, value, f);
	while (root_b != NULL)
	{
		root_b = root_b->next;
		size++;
	}
	return (size - i);
}


/*

70			5
	 		4
	 		3
	 		2
	 		1	==>		DownB return ->1 TIMES REVERSE_B / UpB return -> 8 TIMES ROTATE_B
	 		10
	 		9
	 		8
	 		6

70			1
			10
			9
			8
			6 ==>		4 TIMES	ROTATE_B / 5 TIMES REVERSE_B
			5
	 		4
	 		3
			2


7			9
			8
			6
			5
			4 ==>		2 TIMES ROTATE_B / 7 TIMES REVERSE_B
			3
			2
			1
			10

*/