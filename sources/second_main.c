/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:17:53 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/14 20:16:51 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		all_sort(char *inst, t_help **f, t_list **root_a, t_list **root_b)
{
	if (inst[(*f)->i] == 'p')
	{
		(inst[((*f)->i + 1)] == 'a' ? new_push(root_b, root_a) : new_push(root_a, root_b));
	}
	else if (inst[(*f)->i] == 's')
	{
		(inst[((*f)->i + 1)] == 'a' ? new_swap(root_a) : new_swap(root_b));
	}
	else if (inst[(*f)->i] == 'r')
	{
		if (inst[((*f)->i + 1)] == 'r')
			(inst[((*f)->i + 2)] == 'a' ? new_reverse(root_a) : new_reverse(root_b));
		else if (inst[((*f)->i + 1)] == 'a' || inst[((*f)->i + 1)] == 'b')
			(inst[((*f)->i + 1)] == 'a' ? new_rotate(root_a) : new_rotate(root_b));
	}
}

int			make_sort(t_list *a, t_list *root_a, char *inst, t_help *f)
{
	t_list	*root_b;

	root_b = NULL;
	f->i = 0;
	while (inst[f->i] != '\0')
	{
		all_sort(inst, &f, &root_a, &root_b);
		if (inst[(f->i + 2)] == '\n')
			f->i+=3;
		else if(inst[(f->i + 3)] == '\n')
			f->i+=4;
	}
	free(inst);
	free(f);
	return (make_sort_continue(root_b, root_a));
}

int			make_sort_continue(t_list *root_b, t_list *root_a)
{
	if (root_b == NULL && ft_check_data(root_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_list1(root_a);
	return (0);
}
