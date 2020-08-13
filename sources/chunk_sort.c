/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:13:50 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/13 07:55:40 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		FindMinNumberOfChunkA(t_help **f, t_list **root_a, t_list **a, t_list **root_b)
{
	write(1, "		FINDMINNUMBEROF\n", 24);
	TakeMinMaxValue((*root_a), f);
	(*f)->local_min = (*f)->min;
	(*f)->local_max = (*f)->min + (*f)->chunk_size;
	// print_a((*root_a));
	// printf ("MINI = %d\n", (*f)->min);
	(*f)->up = TakeNumberOperationUp((*root_a), (*f)->local_min, (*f)->local_max);
	(*f)->down = TakeNumberOperationDown((*root_a), (*f)->local_min, (*f)->local_max);
	if ((*f)->up <= (*f)->down)
		MakeMoreRotatePush(root_b, f, root_a);
	else
		MakeMoreReversePush(root_b, f, root_a, a);
}

void		MainSortChunk(t_help *f, t_list *root_a, t_list *a)
{
	int		first_min;
	t_list	*root_b;

	first_min = f->min;
	root_b = NULL;
	int cccc = 33;
	// while (root_a->next != NULL)	
	while (cccc && f->min < (first_min + f->chunk_size))
	{
		write (1, "MAINSORTCHUNK\n", 14);
		cccc--;
		FindMinNumberOfChunkA(&f, &root_a, &a, &root_b);
		print_a(root_a);
		if ((first_min + f->chunk_size) > f->min)
		first_min = f->min;
	}
	printf("min = %d      min+chunk = %d cccc  =%d\n", f->min, (first_min + f->chunk_size), cccc);
}

