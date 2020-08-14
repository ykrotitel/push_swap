/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:18:52 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/14 20:03:17 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		TakeMinMaxValue(t_list *root_a, t_help **f)
{
	t_list	*buff;

	if (root_a == NULL)
		return ;
	buff = root_a;
	(*f)->min = root_a->value;
	(*f)->max = root_a->value;
	while (buff != NULL)
	{
		if (buff->value < (*f)->min)
			(*f)->min = buff->value;
		if (buff->value > (*f)->max)
			(*f)->max = buff->value;
		buff = buff->next;
	}
	return ;
}

void		TakeMinMaxValueB(t_list *stack, t_help **f)
{
	t_list	*buff;

	buff = stack;
	(*f)->min_b = stack->value;
	(*f)->max_b = stack->value;
	while (buff != NULL)
	{
		if (buff->value < (*f)->min_b)
			(*f)->min_b = buff->value;
		if (buff->value > (*f)->max_b)
			(*f)->max_b = buff->value;
		buff = buff->next;
	}
	return ;
}

int			find_chunk(t_help *f, t_list *root_a)
{
	int delta;

	TakeMinMaxValue(root_a, &f);
	delta = f->max - f->min;
	if (f->size >= 0 && f->size < 150)
		f->chunk_size = delta / 5;
	else if (f->size >= 150 && f->size < 300)
		f->chunk_size = delta / 7;
	else if (f->size >= 300)
		f->chunk_size = delta / 10;
	second_step(root_a, f);
	return (0);
}

int			main_continue(t_list *root_a, t_help *f)
{
	if (!check_stack_a(root_a))
	{
		free_list1(root_a);
		free(f);
		return (0);
	}
	return (find_chunk(f, root_a));
}
