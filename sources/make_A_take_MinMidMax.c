/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_take_minmidmax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:25:48 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/23 13:51:41 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		free_list(t_list *root_a)
{
	t_list	*tmp;

	while(root_a != NULL)
	{
		tmp = root_a;
		root_a = root_a->next;
		free(tmp);
	}
}

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
	free_list(root_a);
	free_list(root_b);
	free(f);
	return ;
}


void		second_step(t_list *a, t_list *root_a, t_help *f)
{
	t_list		*b;
	t_list		*root_b;

	b = NULL;
	for_make(&f);
	root_b = b;
	second_step_while(&f, &root_a, &a, &root_b);
	f->cc = 0;
	second_step_secondwhile(&f, &root_a, &root_b);
	sort_stack_a(&root_a, &a, f);
	continue_sort(root_a, root_b, f);
	return ;
}

void		first_takeminmax(t_help **f, t_list *buff)
{
	(*f)->min = buff->value;
	while (buff != NULL)
	{
		if (buff->value >= (*f)->max && ((*f)->maxx = "r"))
			(*f)->max = buff->value;
		if (buff->value <= (*f)->min && ((*f)->minn = "r"))
			(*f)->min = buff->value;
		buff = buff->next;
	}
	(*f)->cc -= 2;
	(*f)->cc /= 2;
	(*f)->tmp = (*f)->min;
	(*f)->sec_tmp = (*f)->max;
}

void		take_min_mid_max(t_list *a, t_list *root_a, int cc, t_help *f)
{
	t_list	*buff;
	t_list	*root_buff;

	for_take_mmm(&f, cc);
	buff = root_a;
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
	int		i;

	i = 1;
	if (ac == 1)
		return (0);
	if (!(first_check(av, ac)))
		return (display_error());
	f = malloc(sizeof(t_help));
	f->cc = 1;
	a = malloc(sizeof(t_list));
	root_a = a;
	i = help_main(av, i, &a);
	while (i != (ac - 1) && av[i])
	{
		i++;
		a->next = malloc(sizeof(t_list));
		a = a->next;
		i = help_main(av, i, &a);
		f->cc++;
	}
	a->next = NULL;
	print_a(root_a);
	if (!(is_overint(root_a)))
		return (display_error());
	main_continue(a, root_a, f);
}

int			is_overint(t_list *root_a)
{
	while (root_a != NULL)
	{
		if (root_a->value > MAX_INT || root_a->value < MIN_INT)
			return (0);
		root_a = root_a->next;
	}
	return (1);
}
