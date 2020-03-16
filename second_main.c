/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:17:53 by acarlett          #+#    #+#             */
/*   Updated: 2020/03/16 19:09:35 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

void		print_a(t_list *root_a)
{
	while (root_a != NULL)
	{
		printf ("A ===> %d\n", root_a->value);
		root_a = root_a->next;
	}
	// write(1, "\n\n", 2);
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

int			ft_check_data(t_list *root_a)
{
	t_list *buff;

	buff = root_a;
	root_a = root_a->next;
	while (root_a != NULL)
	{
		if (buff->value <= root_a->value)
		{
			buff = root_a;
			root_a = root_a->next;
		}
		else
		{
			printf ("buff -> %d and root -> %d\n", buff->value, root_a->value);
			return (0);
		}
	}
	return (1);
}

int			make_sort(t_list *a, t_list *root_a, char *inst)
{
	int		i;
	int		q;
	t_list *b;
	t_list *root_b;

	i = 0;
	b = NULL;
	root_b = b;
	while (inst[i] != '\0')
	{
		while (inst[i] != '\n' && inst[i] != '\0')
		{
			if (inst[i] == 'p' && inst[i + 1] == 'a')
				q = push_a(&root_a, &root_b);
				// q = push_for_push_swap(&b, &a, &root_b, &root_a);
			else if (inst[i] == 'p' && inst[i + 1] == 'b')
				q = push_b(&root_b, &root_a);
				// q = push_in_a(&b, &a, &root_b, &root_a);
			else if (inst[i] == 's' && inst[i + 1] == 'b')
				q = swap_in_b(&root_b, &b);
			else if (inst[i] == 's' && inst[i + 1] == 'a')
				q = swap_in_a(&root_a, &a);
			else if (inst[i] == 's' && inst[i + 1] == 's')
				q = swap(&a, &b, &root_a, &root_b);
			else if (inst[i] == 'r' && inst[i + 1] == 'a')
				q = rotate_a(&root_a);
			else if (inst[i] == 'r' && inst[i + 1] == 'b')
				q = rotate_b(&root_b);
			else if (inst[i] == 'r' && inst[i + 1] == 'r' && (!ft_isalpha(inst[i + 2])))
				q = rotate(&root_a, &root_b);
			else if (inst[i] == 'r' && inst[i + 1] == 'r' && inst[i + 2] == 'a')
				q = reverse_a(&a, &root_a);
			else if (inst[i] == 'r' && inst[i + 1] == 'r' && inst[i + 2] == 'b')
				q = reverse_b(&b, &root_b);
			else if (inst[i] == 'r' && inst[i + 1] == 'r' && inst[i + 2] == 'r')
				q = reverse(&a, &b, &root_a, &root_b);
			i += q;
		// print_a(root_a);
		// print_b(root_b);
		}
		i++;
	}
	free(b);
	b = root_b;
	// print_a(root_a);
	// print_b(root_b);
	if (root_b == NULL && ft_check_data(root_a))
		ft_putstr("OK");
	else
		ft_putstr("KO");
	// if (root_b == NULL)
	// 	printf ("this");
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