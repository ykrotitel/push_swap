/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_A_take_MinMidMax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:25:48 by acarlett          #+#    #+#             */
/*   Updated: 2020/03/03 19:55:31 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int			numbers_of_different_various(t_list *root_a, int max, int min)
{
	t_list	*buff;
	t_list	*tmp;
	int		a;
	int		m;

	buff = root_a;
	a = 0;
	m = max;
	while (min <= max)
	{
		while (buff != NULL)
		{
			if (buff->value == min)
			{
				a++;
			if (min == max)
				return (a);
			}
			buff = buff->next;
		}
		buff = root_a;
		while (buff != NULL)
		{
			if (buff->value < m && buff->value > min)
				m = buff->value;
			buff = buff->next;
		}
		min = m;
		m = max;
		buff = root_a;
	}
	return (a);
}

t_list		*sort_stack_a(t_list **root_a, t_list **a, thelp *f)
{
	t_list *tmp;
	t_list *buff;

	tmp = (*root_a)->next;
	buff = (*root_a);
	if (f->max == (*root_a)->value)
	{
		rotate_a(root_a);
		if (f->mid == (*root_a)->value)
			swap_in_a(root_a, a);
	}
	else if (f->mid == (*root_a)->value && f->max == tmp->value)
	{
		reverse_a(a, root_a);
	}
	else if (f->mid == (*root_a)->value && f->min == tmp->value)
		swap_in_a(root_a, a);
	else if (f->min == (*root_a)->value && f->max == tmp->value)
	{
		reverse_a(a, root_a);
		swap_in_a(root_a, a);
	}
	return (buff);
}

void		print_a(t_list *root_a)
{
	while (root_a != NULL)
	{
		printf ("A => %d\n", root_a->value);
		root_a = root_a->next;
	}
	write(1, "\n\n", 2);
}

void		print_b(t_list 	*root_b)
{
	while (root_b != NULL)
	{
		printf("    b => %d\n", root_b->value);
		root_b = root_b->next;
	}
	write(1, "\n\n", 2);
}

void		continue_sort(t_list *root_a, t_list *root_b, thelp *f)
{
	t_list	*buff;
	t_list	*b;
	t_list	*a;

	b = root_b;
	a = root_a;
	while (b != NULL)
		b = b->next;
	while (a != NULL)
		a = a->next;
		reverse_a(&a, &root_a);
	while (root_b != NULL)
	{
		if(root_a->value < root_b->value)
		{
			rotate_a(&root_a);
			push_in_b(&b, &a, &root_a, &root_b);
			push_in_b(&b, &a, &root_b, &root_a);
		}
		else
			reverse_a(&a, &root_a);
		
	}
	while (f->min != root_a->value)
		reverse_a(&a, &root_a);
	// print_a(root_a);
	// print_b(root_b);
	return ;
}

void		second_step(t_list *a, t_list *root_a, thelp *f)
{
	t_list	*b;
	t_list 	*buf;
	t_list	*buff_root;
	t_list	*root_b;
	int		c;

	b = NULL;
	root_b = b;
	buf = root_a;
	buff_root = root_a;
	while (buf != NULL)
	{
		if(buf->value > f->min  && buf->value < f->mid)
		{
			c = buf->value;
			while (root_a->value != c)
			{
				rotate_a(&root_a);
			}
			buf = root_a;
			push_in_b(&b, &a, &root_b, &root_a);
		}
		buf = buf->next;
	}
	buf = root_a;
	while (buf != NULL)
	{
		if(buf->value > f->mid  && buf->value < f->max)
		{
			c = buf->value;
			while (root_a->value != c)
			{
				rotate_a(&root_a);
			}
			buf = root_a;
			push_in_b(&b, &a, &root_b, &root_a);
		}
		buf = buf->next;
	}
	sort_stack_a(&root_a, &a, f);
	// print_a(root_a);
	// print_b(root_b);
	continue_sort(root_a, root_b, f);
	return ;
}

void		take_min_mid_max(t_list *a, t_list *root_a, int cc)
{
	t_list	*buff;
	t_list	*root_buff;
	thelp	*f;

	f = malloc(sizeof(thelp));
	f->mid = 0;
	f->max = 0;
	f->c = 0;
	f->cc = cc;
	f->minn = NULL;
	f->midd = NULL;
	f->maxx = NULL;
	buff = root_a;
	f->min = buff->value;
	while(buff != NULL)
	{
		if (buff->value >= f->max && (f->maxx = "r"))
			f->max = buff->value;
		if (buff->value <= f->min && (f->minn = "r"))
			f->min = buff->value;
		buff = buff->next;
	}
	// printf ("min = %d and max = %d\n", f->min, f->max);
	f->c = numbers_of_different_various(root_a, f->max, f->min);
	// printf ("c = %d and cc = %d\n", f->c, f->cc);
	if (f->c != f->cc)
	{
		ft_putstr("Errorrrr");
		return ;
	}
	f->c -= 2;
	f->c /= 2;
	// printf ("counter ==  %d\n", f->c);
	buff = root_a;
	root_buff = root_a;
	f->tmp = f->min;
	f->sec_tmp = f->max;
	if (f->c > 0)
	{
		while (f->c >= 0)
		{
			while (buff != NULL)
			{
				if (buff->value > f->tmp && buff->value < f->sec_tmp)
					f->sec_tmp = buff->value;
				buff = buff->next;
			}
			f->tmp = f->sec_tmp;
			f->sec_tmp = f->max;
			f->c--;
			buff = root_buff;
		}
		f->mid = f->tmp;
		f->midd = "r";
	}
	else
	{
		buff = root_a;
		while (buff->next != NULL)
		{
			if ((buff->value != f->min) && (buff->value != f->max))
			{
				f->midd = "r";
				f->mid = buff->value;
			}
			buff = buff->next;
		}
	}
	buff = root_a;
	if (f->midd == NULL && (f->midd = "r"))
		f->mid = buff->value;
	// printf ("min -> %d\nflag_min = %s\nmid -> %d\nflag_mid = %s\nmax -> %d\nflag_max = %s\n\n\n", f->min, f->minn, f->mid, f->midd, f->max, f->maxx);
	f->f_min = f->minn;
	f->f_mid = f->midd;
	f->f_max = f->maxx;
	second_step(a, root_a, f);
	return ;
	push_numbers_in_b(a, root_a, f);
}

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*root_a;
	thelp	*f;
	int		i;

	i = 1;
	f = malloc(sizeof(thelp));
	f->cc = 1;
	a = malloc(sizeof(t_list));
	root_a = a;
	a->value = ft_atoi(av[i]);
	while(i != (ac - 1))
	{
		i++;
		a->next = malloc(sizeof(t_list));
		a = a->next;
		a->value = ft_atoi(av[i]);
		f->cc++;
	}
	a->next = NULL;
	take_min_mid_max(a, root_a, f->cc);
	return (0);
}