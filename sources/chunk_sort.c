/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:13:50 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/15 16:40:35 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		findminnumberofchunka(t_help **f, t_list **root_a, t_list **root_b)
{
	(*f)->local_min = (*f)->min;
	(*f)->local_max = (*f)->min + (*f)->chunk_size;
	(*f)->up = takenumberoperationup((*root_a),
	(*f)->local_min, (*f)->local_max);
	(*f)->down = takenumberoperationdown((*root_a),
	(*f)->local_min, (*f)->local_max);
	if ((*f)->up <= (*f)->down)
		makemorerotatepush(root_b, f, root_a);
	else
		makemorereversepush(root_b, f, root_a);
	takeminmaxvalueb((*root_b), f);
}

void		mainsortchunk(t_help *f, t_list **root_a)
{
	int		first_min;
	t_list	*root_b;

	first_min = f->min;
	root_b = NULL;
	while ((*root_a) != NULL)
	{
		findminnumberofchunka(&f, root_a, &root_b);
		if ((first_min + f->chunk_size) > f->min)
			first_min = f->min;
	}
	f->up = takenumberoperationupb(root_b, f->max_b, f);
	f->down = takenumberoperationdownb(root_b, f->max_b, f);
	if (f->up <= f->down)
		while (f->max_b != root_b->value)
			new_rotate(&root_b) && write(1, "rb\n", 3);
	else
		while (f->max_b != root_b->value)
			new_reverse(&root_b) && write(1, "rrb\n", 4);
	while (root_b != NULL)
		new_push(&root_b, root_a) && write(1, "pa\n", 3);
}
