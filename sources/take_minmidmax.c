/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_minmidmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:21:29 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/07 18:33:41 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		continue_sort(t_list *root_a, t_list *root_b, t_help *f)
{
	t_list	*b;
	t_list	*a;

	b = root_b;
	a = root_a;
	for_make(&f);
	while (b != NULL && b->next != NULL)
		b = b->next;
	while (a->next != NULL)
		a = a->next;
	while (root_b != NULL)
	{
		if (root_a->value > root_b->value && a->value > root_b->value)
			reverse_a(&a, &root_a, 0) && write(1, "rra\n", 4);
		else if (root_a->value < root_b->value)
			rotate_a(&root_a) && write(1, "ra\n", 3);
		else
			push_a(&root_a, &root_b) && write(1, "pa\n", 3);
	}
	while (f->min != root_a->value)
	{
		reverse_a(&a, &root_a, 0) && write(1, "rra\n", 4);
	}
	all_free(root_a, root_b);
	free(f);
}

void		second_step(t_list *a, t_list *root_a, t_help *f)
{
	t_list		*b;
	t_list		*root_b;

	if (f->size <= 3)
	{
		sort_only_2_3(&root_a, &a, f);
		free_list(root_a);
		free(f);
	}
	else
	{
		b = NULL;
		for_make(&f);
		root_b = b;
		second_step_while(&f, &root_a, &a, &root_b);
		f->cc = 0;
		second_step_secondwhile(&f, &root_a, &root_b, &a);
		sort_stack_a(&root_a, &a, f);
		continue_sort(root_a, root_b, f);
	}
	return ;
}

void		take_min_mid_max(t_list *a, t_list *root_a, int cc, t_help *f)
{
	t_list	*buff;
	t_list	*root_buff;

	buff = root_a;
	for_take_mmm(&f, cc, buff);
	first_takeminmax(&f, root_a);
	root_buff = root_a;
	if (f->cc > 0)
		make_first_if(&f, buff, root_buff);
	else
		make_first_else(&f, root_a);
	if (f->midd == NULL && (f->midd = "r"))
		f->mid = buff->value;
	f->f_min = f->minn;
	f->f_mid = f->midd;
	f->f_max = f->maxx;
	f->cc = cc;
	second_step(a, root_a, f);
}

int			main(int ac, char **av)
{
	t_list	*a;
	t_list	*root_a;
	t_help	*f;

	if (ac == 1)
		return (0);
	if (!(first_check(av, ac)))
		return (display_error(0));
	f = malloc(sizeof(t_help));
	for_f(&f, &root_a);
	if (check_line(av[f->i]) && (a = malloc(sizeof(t_list))))
		help_for_ps_main(&root_a, &a, &f);
	f->i = help_main(av, &a, &f, &root_a);
	while (f->i != (ac - 1) && av[++(f->i)])
	{
		if ((check_line(av[f->i])) && f->ccc &&
		(a->next = malloc(sizeof(t_list))) && (f->cc++))
			a = a->next;
		f->i = help_main(av, &a, &f, &root_a);
	}
	return (main_for_norm(a, root_a, f));
}

int			main_for_norm(t_list *a, t_list *root_a, t_help *f)
{
	f->size = f->cc;
	if (root_a == NULL)
	{
		free(f);
		return (0);
	}
	if (!(is_overint(root_a)))
	{
		free(f);
		free_list(root_a);
		return (display_error(0));
	}
	return (main_continue(a, root_a, f));
}
