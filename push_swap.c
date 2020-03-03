/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:06:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/03/03 18:51:03 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

// int		check_min_max(int value, thelp *f)
// {
// 	if (value == f->min && f->minn != NULL)
// 	{
// 		f->minn = NULL;
// 		return (1);
// 	}
// 	if (value == f->mid && f->midd != NULL)
// 	{
// 		f->midd = NULL;
// 		return (1);
// 	}
// 	if (value == f->max && f->maxx != NULL)
// 	{
// 		f->maxx = NULL;
// 		return (1);
// 	}
// 	return (0);
// }

// t_list	*rewrite(t_list *buff)
// {
// 	t_list	*tmp;
// 	t_list 	*root_tmp;
// 	t_list	*t;

// 	tmp = malloc(sizeof(t_list));
// 	root_tmp = tmp;
// 	if (buff == NULL || buff->next == NULL)
// 		return (NULL);
// 	while (buff->next != NULL)
// 	{
// 		tmp->value = buff->value;
// 		tmp->next = malloc(sizeof(t_list));
// 		tmp = tmp->next;
// 		tmp->next = NULL;
// 		buff = buff->next;
// 		write (1, "Q\n", 2);
// 	}
// 	return (root_tmp);
// 	/*t = buff->next;
// 	// if (t == NULL)
// 	// 	return (NULL);
// 	tmp->value = buff->value;
// 		write (1, "checkkk\n", 8);
// 	if (t && t != NULL && t->next != NULL)
// 	{
// 		while (t != NULL && t->next != NULL)
// 		{
// 			buff = buff->next;
// 			tmp->next = malloc(sizeof(t_list));
// 			tmp = tmp->next;
// 			t = t->next;
// 			tmp->value = buff->value;
// 		}
// 	}
// 	write (1, "check\n", 6);
// 	tmp->next = NULL;
// 	*/
// }

// int		push_numbers_in_b(t_list *a, t_list *root_a, thelp *f)
// {
// 	t_list	*b;
// 	t_list	*root_b;
// 	t_list	*b_root;
// 	t_list	*buff;
// 	t_list	*tmp;

// 	b = malloc(sizeof(t_list));
// 	b->next = NULL;
// 	root_b = b;
// 	buff = root_a;
// 	tmp = root_a;
// 	f->ff = 0;
// 	f->f = (f->midd == NULL ? 0 : 1);
// 	while(buff != NULL)
// 	{
// 		printf ("\nfirst buff->value ->  %d\n", buff->value);
// 		if (((buff->value > f->min) && (buff->value < f->mid)) || (buff->value == f->min && f->minn == NULL) || (buff->value == f->mid && f->midd == NULL))
// 		{
// 			write (1,"11111this\n", 10);
// 			// b = malloc(sizeof(t_list));
// 			// if (root_b == NULL)
// 			// 	root_b = b;
// 			// b->value = buff->value;
// 			// b->next = NULL;
// 			// b = b->next;
// 			// b->next = malloc(sizeof(t_list));
// 			// b = b->next;
// 			f->ff = 1;
// 			b->value = buff->value;
// 			b->next = NULL;
// 			printf ("  b->value = %d\n", b->value);
// 			if (buff == NULL)
// 				break ;
// 		}
// 		if (check_min_max(buff->value, f))
// 		{
// 			write(1, "1111111111skip elem   ", 23);
// 			printf("-> %d\n", buff->value);
// 			buff = buff->next;
// 			continue ;
// 			if (buff == NULL)
// 				break ;
// 		}
// 		if (buff == root_a)
// 		{
// 			write(1, "1111111111push from root   ", 27);
// 			printf ("=> %d\n", buff->value);
// 			root_a = root_a->next;
// 			free(buff);
// 			buff = root_a;
// 			tmp = root_a;
// 			if (buff == NULL)
// 				break ;
// 		}
// 		else if (((buff->value > f->min) && (buff->value < f->mid)) || (buff->value == f->min && f->minn == NULL) || (buff->value == f->mid && f->midd == NULL))
// 		{
// 			write(1, "1111111111usually push   ", 25);
// 			printf (" => %d\n", buff->value);
// 			printf ("tmp => %d\n", tmp->value);
// 			while(tmp != NULL && tmp->next != buff)
// 				tmp = tmp->next;
// 			tmp->next = buff->next;
// 			free(buff);
// 			buff = tmp->next;
// 			tmp = root_a;
// 			if (buff == NULL)
// 				break ;
// 		}
// 		else
// 		{
// 			write (1, "wright there\n", 13);
// 			buff = buff->next;
// 			if (buff == NULL)
// 				break ;
// 		}
// 		b->next = malloc(sizeof(t_list));
// 		b = b->next;
// 	}
// 	b->next = NULL;
// 	buff = root_a;
// 	tmp = root_a;
// 	while (root_a != NULL)
// 	{
// 		printf ("A -> %d\n", root_a->value);
// 		root_a = root_a->next;
// 	}
// 	root_a = buff;
// 	buff = root_b;
// 	while (root_b != NULL)
// 	{
// 		printf ("\n	this B -> %d", root_b->value);
// 		root_b = root_b->next;
// 	}
// 	root_b = buff;
// 	buff = root_a;
// 	f->midd = (f->f == 1 ? "r" : NULL);
// 	f->minn = f->f_min;
// 	f->midd = f->f_mid;
// 	f->maxx = f->f_max;
// 	while(buff != NULL)
// 	{
// 		if (((buff->value > f->mid) && (buff->value < f->max)) || (buff->value == f->mid && f->midd == NULL) || (buff->value == f->max && f->maxx == NULL))
// 		{
// 			write (1,"22222this", 9);
// 			// b = malloc(sizeof(t_list));
// 			// if (root_b == NULL)
// 			// 	root_b = b;
// 			// b->value = buff->value;
// 			// b->next = NULL;
// 			// b = b->next;
// 			if (f->ff == 1)
// 			{
// 				f->ff = 0;
// 				b = malloc(sizeof(t_list));
// 			}
// 			b->value = buff->value;
// 			b->next = NULL;
// 			printf ("  b->value = %d\n", b->value);
// 			if (buff == NULL)
// 				break ;
// 		}
// 		if (check_min_max(buff->value, f))
// 		{
// 			write(1, "2222222222skip elem   ", 23);
// 			printf (" = %d\n", buff->value);		
// 			buff = buff->next;
// 			continue ;
// 		}
// 		if (buff == root_a)
// 		{
// 			write(1, "2222222222push from root", 24);
// 			printf (" = %d\n", buff->value);
// 			root_a = root_a->next;
// 			free(buff);
// 			buff = root_a;
// 			tmp = root_a;
// 			if (buff == NULL)
// 				break ;
// 		}
// 		else if (((buff->value > f->mid) && (buff->value < f->max)) || (buff->value == f->mid && f->midd == NULL) || (buff->value == f->max && f->maxx == NULL))
// 		{
// 			write(1, "2222222222usually push", 22);
// 			printf (" = %d\n", buff->value);
// 			/*while(tmp->next != buff)
// 				tmp = tmp->next;
// 			tmp->next = buff->next;
// 			free(buff);
// 			buff = tmp->next;
// 			tmp = root_a;*/
// 			while(tmp != NULL && tmp->next != buff)
// 				tmp = tmp->next;
// 			tmp->next = buff->next;
// 			free(buff);
// 			buff = tmp->next;
// 			tmp = root_a;
// 			if (buff == NULL)
// 				break ;
// 		}
// 		else
// 		{
// 			buff = buff->next;
// 			if (buff == NULL)
// 				break ;
// 		}
// 		b->next = malloc(sizeof(t_list));
// 		b = b->next;
// 	}
// 	// if (b == root_b)
// 	// 	free(b);
// 	// else
// 	// {
// 	// 	b->next = NULL;
// 	// 	buff = root_b;
// 	// }
// 	write (1, "OUT\n", 4);
// 	buff = sort_stack_a(root_a, a, f);
// 	root_a = buff;
// 	while (root_a != NULL)
// 	{
// 		printf ("A -> %d\n", root_a->value);
// 		root_a = root_a->next;
// 	}
// 	b_root = rewrite(root_b);
// 	root_b = b_root;
// 	while (root_b != NULL)
// 	{
// 		printf ("\n	this B -> %d", root_b->value);
// 		root_b = root_b->next;
// 	}
// 	return (0);
// }