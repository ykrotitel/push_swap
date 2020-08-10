/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:13:50 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/10 22:43:37 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		FindMinNumberOfChunkA(t_help **f, t_list **root_a, t_list **a, t_list **root_b)
{
	int min;
	int max;

	min = (*f)->min;
	max = (*f)->min + (*f)->chunk_size;
	(*f)->up = TakeNumberOperationUp((*root_a), min, max); 
	/* 				^
					|
		Ищем элемент певрого чанка сверху 
	*/
	(*f)->down = TakeNumberOperationDown((*root_a), min, max);
	/*				^
					|
		Ищем первый элемент чанка снизу
	*/
	if ((*f)->up < (*f)->down)
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
	while (f->min != (first_min + f->chunk_size))
	{
		/* работаем пока минимальный элемент в стеке А
				не станет равен верхней границе чанка */
		FindMinNumberOfChunkA(&f, &root_a, &a, &root_b);
		TakeMinMaxValue(a, root_a, &f);
	}
}

