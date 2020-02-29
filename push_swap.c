/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:06:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/29 15:13:22 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int		check_min_max(int value, thelp *f)
{
	if (value == f->min && f->minn != NULL)
	{
		f->minn = NULL;
		return (1);
	}
	if (value == f->mid && f->midd != NULL)
	{
		f->midd = NULL;
		return (1);
	}
	if (value == f->max && f->maxx != NULL)
	{
		f->maxx = NULL;
		return (1);
	}
	return (0);
}

t_list	*rewrite(t_list *buff)
{
	t_list	*tmp;
	t_list 	*root_tmp;
	t_list	*t;

	tmp = malloc(sizeof(t_list));
	root_tmp = tmp;
	tmp->value = buff->value;
	t = buff->next;
	// if (t == NULL)
	// 	return(NULL);
	while (t != NULL && t->next != NULL)
	{
		buff = buff->next;
		tmp->next = malloc(sizeof(t_list));
		tmp = tmp->next;
		t = t->next;
		tmp->value = buff->value;
	}
	tmp->next = NULL;
	return (root_tmp);
}

int		push_numbers_in_b(t_list *a, t_list *root_a, thelp *f)
{
	t_list	*b;
	t_list	*root_b;
	t_list	*b_root;
	t_list	*buff;
	t_list	*tmp;

	b = malloc(sizeof(t_list));
	root_b = b;
	buff = root_a;
	tmp = root_a;
	f->f = (f->midd == NULL ? 0 : 1);
	while(buff != NULL)
	{
		printf ("\nfirst buff->value ->  %d\n", buff->value);
		if (((buff->value > f->min) && (buff->value < f->mid)) || (buff->value == f->min && f->minn == NULL) || (buff->value == f->mid && f->midd == NULL))
		{
			write (1,"11111this\n", 10);
			b->value = buff->value;
			b->next = malloc(sizeof(t_list));
			b = b->next;
			b->next = NULL;
		}
		if (check_min_max(buff->value, f))
		{
			write(1, "1111111111skip elem   ", 23);
			printf("-> %d\n", buff->value);
			buff = buff->next;
			continue ;
		}
		if (buff == root_a)
		{
			write(1, "1111111111push from root   ", 27);
			printf ("=> %d\n", buff->value);
			root_a = root_a->next;
			free(buff);
			buff = root_a;
		}
		else if (((buff->value > f->min) && (buff->value < f->mid)) || (buff->value == f->min && f->minn == NULL) || (buff->value == f->mid && f->midd == NULL))
		{
			write(1, "1111111111usually push   ", 25);
			printf (" => %d\n", buff->value);
			while(tmp->next != buff)
				tmp = tmp->next;
			tmp->next = buff->next;
			free(buff);
			buff = tmp->next;
			tmp = root_a;
		}
		else
			buff = buff->next;
		
	}
	buff = root_a;
	tmp = root_a;
	f->midd = (f->f == 1 ? "r" : NULL);
	f->minn = f->f_min;
	f->midd = f->f_mid;
	f->maxx = f->f_max;
	while(buff != NULL)
	{
		if (((buff->value > f->mid) && (buff->value < f->max)) || (buff->value == f->mid && f->midd == NULL) || (buff->value == f->max && f->maxx == NULL))
		{
			write (1,"22222this\n", 10);
			b->value = buff->value;
			b->next = malloc(sizeof(t_list));
			b = b->next;
		}
		if (check_min_max(buff->value, f))
		{
			write(1, "2222222222skip elem   ", 23);
			printf (" = %d\n", buff->value);		
			buff = buff->next;
			continue ;
		}
		if (buff == root_a)
		{
			write(1, "2222222222push from root\n", 25);
			root_a = root_a->next;
			free(buff);
			buff = root_a;
		}
		else if (((buff->value > f->mid) && (buff->value < f->max)) || (buff->value == f->mid && f->midd == NULL) || (buff->value == f->max && f->maxx == NULL))
		{
			write(1, "2222222222usually push\n", 23);
			while(tmp->next != buff)
				tmp = tmp->next;
			tmp->next = buff->next;
			free(buff);
			buff = tmp->next;
			tmp = root_a;
		}
		else
			buff = buff->next;
	}
	if (b == root_b)
		free(b);
	else
	{
		b->next = NULL;
		buff = root_b;
	}
	while (root_a != NULL)
	{
		printf ("A -> %d\n", root_a->value);
		root_a = root_a->next;
	}
	b_root = rewrite(root_b);
	root_b = b_root;
	while (root_b != NULL)
	{
		printf ("\n	this B -> %d", root_b->value);
		root_b = root_b->next;
	}
	return (0);
}

int			numbers_of_different_various(t_list *root, int max, int min)
{
	int		a;
	int 	b;
	int		f;
	int		c;
	t_list	*tmp;
	t_list	*buff;

	a = 0;
	c = min;
	tmp = root;
	f = max;
	buff = tmp->next;
	while (tmp != NULL)
	{
		a++;
		tmp = tmp->next;
	}
	tmp = root;
	while (f != 0)
	{
		while(tmp->next != NULL)
		{
			if (tmp->value < c && tmp->value > min)
				c = tmp->value;
			tmp = tmp->next;
		}
		tmp = root;
		while (tmp->next != NULL)
		{
			if (tmp->value == c)
				a--;
			tmp = tmp->next;
		}
		a++;
		tmp = root;
		min = c;
		f--;
		if (c == max)
			break ;
		c = max;
	}
	a--;
	a -= 2;
	a /= 2;
	return (a);
}

void		take_min_mid_max(t_list *a, t_list *root_a)
{
	t_list	*buff;
	t_list	*root_buff;
	thelp	*f;

	f = malloc(sizeof(thelp));
	f->mid = 0;
	f->max = 0;
	f->c = 0;
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
	f->c = numbers_of_different_various(root_a, f->max, f->min);
	printf ("counter ==  %d\n", f->c);
	buff = root_a;
	root_buff = root_a;
	f->tmp = f->min;
	f->sec_tmp = f->max;
	if (f->c > 0)
	{
		while (f->c >= 0)
		{
			while (buff->next != NULL)
			{
				if (buff->value > f->tmp && buff->value < f->sec_tmp)
					f->sec_tmp = buff->value;
				buff = buff->next;
				// write(1, "TR\n", 3);
			}
			// write(1, "RT\n", 3);
			// printf ("this is sec_tmp -> %d\n", f->sec_tmp);
			f->tmp = f->sec_tmp;
			f->sec_tmp = f->max;
			f->c--;
			root_buff = root_buff->next;
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
	printf ("min -> %d\nflag_min = %s\nmid -> %d\nflag_mid = %s\nmax -> %d\nflag_max = %s\n\n\n", f->min, f->minn, f->mid, f->midd, f->max, f->maxx);
	f->f_min = f->minn;
	f->f_mid = f->midd;
	f->f_max = f->maxx;
	push_numbers_in_b(a, root_a, f);
}

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*root_a;
	int		i;

	i = 1;
	a = malloc(sizeof(t_list));
	root_a = a;
	a->value = ft_atoi(av[i]);
	while(i != (ac - 1))
	{
		i++;
		a->next = malloc(sizeof(t_list));
		a = a->next;
		a->value = ft_atoi(av[i]);
	}
	a->next = NULL;
	take_min_mid_max(a, root_a);
	return (0);
}