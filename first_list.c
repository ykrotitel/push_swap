/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:17:53 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/14 22:55:59 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int			make_sort(t_list *a, t_list *root_a, char *inst)
{
	int		i;
	t_list *b;
	t_list *root_b;

	i = 0;
	b = NULL;
	root_b = b;
	while (inst[i] != '\0')
	{
		while (inst[i] != '\n')
		{
			if (inst[i] == 'p' && inst[i + 1] == 'b')
				push_in_b(&b, &a, &root_b, &root_a);
			else if (inst[i] == 'p' && inst[i + 1] == 'a')
				push_in_a(&b, &a, &root_b, &root_a);
			else if (inst[i] == 's' && inst[i + 1] == 'b')
				swap_in_b(&root_b, &b);
			else if (inst[i] == 's' && inst[i + 1] == 'a')
				swap_in_a(&root_a, &a);
			else if (inst[i] == 's' && inst[i + 1] == 's')
				swap(&a, &b, &root_a, &root_b);
			else if (inst[i] == 'r' && inst[i + 1] == 'a')
				rotate_in_a(&root_a, &a);
			i++;
		}
		i++;
	}
	free(b);
	b = root_b;
	while(root_a != NULL)
	{
		printf ("first  -> %d\n", root_a->value);
		root_a = root_a->next;
	}
	while(root_b != NULL)
	{
		printf ("second -> %d\n", root_b->value);
		root_b = root_b->next;
	}
	return (0);
}

int			make_list_a(int argc, long long int arr[argc], char *inst)
{
	t_list	*a;
	t_list	*root_a;
	int		i;

	a = malloc(sizeof(t_list));
	root_a = a;
	i = 0;
	a->value = arr[i];
	while (i != (argc - 2))
	{
		a->next = malloc(sizeof(t_list));
		a = a->next;
		i++;
		a->value = arr[i];
	}
	a->next = NULL;
	a = root_a;
	make_sort(a, root_a, inst);
	return (0);
}