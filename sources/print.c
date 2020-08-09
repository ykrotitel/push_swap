/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:28:44 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/09 20:02:06 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void				print_a(t_lst *root_a)
{
	while (root_a != NULL)
	{
		printf ("A ===> %ld\n", root_a->value);
		root_a = root_a->next;
	}
}

void				print_b(t_lst 	*root_b)
{
	while (root_b != NULL)
	{
		printf("    b => %ld\n", root_b->value);
		root_b = root_b->next;
	}
	write(1, "\n\n", 2);
}

void				print(t_list *root_a)
{
	while (root_a != NULL)
	{
		printf ("	A ===> %d\n", root_a->value);
		root_a = root_a->next;
	}
}