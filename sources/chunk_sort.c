/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:13:50 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/14 20:10:25 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		FindMinNumberOfChunkA(t_help **f, t_list **root_a, t_list **root_b)
{
	(*f)->local_min = (*f)->min;
	(*f)->local_max = (*f)->min + (*f)->chunk_size;
	(*f)->up = TakeNumberOperationUp((*root_a), (*f)->local_min, (*f)->local_max);
	(*f)->down = TakeNumberOperationDown((*root_a), (*f)->local_min, (*f)->local_max);
	if ((*f)->up <= (*f)->down)
		MakeMoreRotatePush(root_b, f, root_a);
	else
		MakeMoreReversePush(root_b, f, root_a);
	TakeMinMaxValueB((*root_b), f);
}

void		MainSortChunk(t_help *f, t_list **root_a)
{
	int		first_min;
	t_list	*root_b;

	first_min = f->min;
	root_b = NULL;
	while ((*root_a) != NULL)
	{
		FindMinNumberOfChunkA(&f, root_a, &root_b);
		if ((first_min + f->chunk_size) > f->min)
		first_min = f->min;
	}
	f->up = TakeNumberOperationUpB(root_b, f->max_b, f);
	f->down = TakeNumberOperationDownB(root_b, f->max_b, f);
	if (f->up <= f->down)
		while (f->max_b != root_b->value)
			new_rotate(&root_b) && write(1, "rb\n", 3);
	else
		while (f->max_b != root_b->value)
			new_reverse(&root_b) && write(1, "rrb\n", 4);
	while (root_b != NULL)
		new_push(&root_b, root_a) && write(1, "pa\n", 3);
}

