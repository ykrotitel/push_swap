/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:39:53 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/11 23:11:30 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		SortingB_Push(t_list **root_a, t_list **root_b, t_help **f)
{
	t_list	*buff;
	t_list	*s_buff;

	buff = (*root_b)->next;
	s_buff = buff->next;
}


/*
	1			2
	2 -> swap, 	1 -> SUCCESS
	3			3 

	1
	3 -> SUCCESS
	2

	2
	1 -> SUCCESS
	3

	2			3
	3 -> swap, 	2 -> SUCCESS
	1			1

	3			1
	1 -> swap, 	3 -> SUCCESS
	2			2

	3
	2 -> SUCCESS
	1

*/