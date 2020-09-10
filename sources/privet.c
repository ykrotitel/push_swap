/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 21:58:45 by acarlett          #+#    #+#             */
/*   Updated: 2020/09/10 18:03:37 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		privet_3(t_list **root_a, int com)
{
	if (com == 1)
	{
		new_rotate(root_a);
		write(1, "ra\n", 3);
	}
	else if (com == 2)
	{
		new_reverse(root_a);
		write(1, "rra\n", 4);
	}
	else if (com == 3)
	{
		new_swap(root_a);
		write(1, "sa\n", 3);
	}
}

void		privet_2(t_list **root_a, t_list **root_b, int com)
{
	if (com == 4)
	{
		new_reverse(root_b);
		write(1, "rrb\n", 4);
	}
	else if (com == 5)
	{
		new_reverse(root_a);
		write(1, "rra\n", 4);
	}
	else if (com == 6)
	{
		new_swap(root_a);
		write(1, "sa\n", 3);
	}
	else if (com == 7)
	{
		new_swap(root_b);
		write(1, "sb\n", 3);
	}
}

void		privet(t_list **root_a, t_list **root_b, int com)
{
	if (com == 0)
	{
		new_push(root_a, root_b);
		write(1, "pb\n", 3);
	}
	else if (com == 1)
	{
		new_push(root_b, root_a);
		write(1, "pa\n", 3);
	}
	else if (com == 2)
	{
		new_rotate(root_b);
		write(1, "rb\n", 3);
	}
	else if (com == 3)
	{
		new_rotate(root_a);
		write(1, "ra\n", 3);
	}
	privet_2(root_a, root_b, com);
}
