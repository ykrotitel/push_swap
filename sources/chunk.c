/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:18:52 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/13 02:41:46 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		TakeMinMaxValue(t_list *root_a, t_help **f)
{
	t_list	*buff;

	buff = root_a;
	(*f)->min = root_a->value;
	(*f)->max = root_a->value;
	while (buff->next != NULL)
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
	while (buff->next != NULL)
	{
		if (buff->value < (*f)->min_b)
			(*f)->min_b = buff->value;
		if (buff->value > (*f)->max_b)
			(*f)->max_b = buff->value;
		buff = buff->next;
	}
	return ;
}

int			find_chunk(t_help *f, t_list *a, t_list *root_a)
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
	// if (f->size <= 50)
	// 	f->chunk_size = 10;
	// else if (f->size > 50 && f->size < 100)
	// 	f->chunk_size = 15;
	// else if (f->size >= 100 && f->size < 200)
	// 	f->chunk_size = 20;
	// else if (f->size >= 200 && f->size < 300)
	// 	f->chunk_size = 30;
	// else if (f->size >= 300 && f->size < 400)
	// 	f->chunk_size = 40;
	// else if (f->size >= 400 && f->size < 500)
	// 	f->chunk_size = 45;
	// else if (f->size >= 500)
	// 	f->chunk_size = 50;	
	printf ("min  = %d   max = %d   chunk_size = %d   f->cc = %d\n", f->min, f->max, f->chunk_size, f->cc);
	second_step(a, root_a, f);
	return (0);
}

int			test_function(t_help *f, t_list *root_a)
{
	write (1, "ok!\n", 4);
	print_a(root_a);
	new_swap(&root_a);
	write (1, "\nSA\n", 4);
	print_a(root_a);
	return (1);
}

int			main_continue(t_list *a, t_list *root_a, t_help *f)
{
	if (!check_stack_a(root_a))
	{
		free_list1(root_a);
		free(f);
		return (0);
	}

	// return (test_function(f, root_a));

	return (find_chunk(f, a, root_a));
}
