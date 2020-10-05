/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_and_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:21:29 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/15 16:34:52 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		second_step(t_list *root_a, t_help *f)
{
	if (f->size <= 5)
		sort_only_2_3_5(&root_a, f);
	else
	{
		for_make(&f);
		mainsortchunk(f, &root_a);
	}
	free(f);
	free_list1(root_a);
	return ;
}
