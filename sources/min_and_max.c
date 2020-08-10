/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_and_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:21:29 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/10 22:01:00 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		second_step(t_list *a, t_list *root_a, t_help *f)
{
	if (f->size <= 3)
	{
		sort_only_2_3(&root_a, &a, f);
		free(f);
		free_list1(root_a);
	}
	else
	{
		for_make(&f);
		MainSortChunk(f, root_a, a);
	}
	free(f);
	free_list1(root_a);
	return ;
}
