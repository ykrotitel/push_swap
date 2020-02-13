/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:17:53 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/13 23:18:25 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int			make_sort(t_list *a,t_list *root_a, char *inst)
{
	int		i;
	t_list *b;
	t_list *root_b;
    t_list *buff;
    t_list *buff_root;

	i = 0;
	b = malloc(sizeof(t_list));
	root_b = b;
	while (inst[i] != '\0')
	{
		while (inst[i] != '\n')
		{
			if (inst[i] == 'p' && inst[i + 1] == 'b')
				push_in_b(&b, &a, &root_b, &root_a);
			i++;
		}
		i++;
	}
	printf ("thiiiis -> %d\n", b->value);
	free(b);
	b = root_b;
	while(a != NULL)
	{
		printf ("first  -> %d\n", a->value);
		a = a->next;
	}
	while(b != NULL)
	{
		printf ("second -> %d\n", b->value);
		b = b->next;
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