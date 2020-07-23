/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_a_print_b_pushswap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:50:58 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/23 13:07:38 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		print_a(t_list *root_a)
{
	while (root_a != NULL)
	{
		printf ("A ===> %ld\n", root_a->value);
		root_a = root_a->next;
	}
}

void		print_b(t_list 	*root_b)
{
	while (root_b != NULL)
	{
		printf("    b => %ld\n", root_b->value);
		root_b = root_b->next;
	}
	write(1, "\n\n", 2);
}

