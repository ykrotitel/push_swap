/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:13:50 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/09 20:58:08 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		take_numberOperation_up(t_list *root_a, int min, int max)
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

int			take_numberOperation_down(t_list *root_a, int min, int max)
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

void		find_min_number_of_chunk(t_list *b, t_list *root_b, t_help *f, t_list *root_a)
{
	int min;
	int max;

	min = f->min;
	max = f->min + f->chunk_size;
	f->q = take_numberOperation_up(root_a, min, max);
	f->w = take_numberOperation_down(root_a, min, max);
	printf ("q = %d\nw = %d\n", f->q, f->w);
}

void		first_sort_chunk(t_list *b, t_list *root_b, t_help *f, t_list *root_a)
{
	int		count;

	count = 0;
	while (count != f->chunk_size)
	{
		find_min_number_of_chunk(b, root_b, f, root_a);
		count++;
	}
}
