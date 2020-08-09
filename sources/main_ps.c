/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:32:33 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/09 20:33:18 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int			main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*root_a;
	t_help	*f;

	if (ac == 1)
		return (0);
	if (!(first_check(av, ac)))
		return (display_error(0));
	f = malloc(sizeof(t_help));
	for_f(&f, &root_a);
	if (check_line(av[f->i]) && (a = malloc(sizeof(t_lst))))
		help_for_ps_main(&root_a, &a, &f);
	f->i = help_main(av, &a, &f, &root_a);
	while (f->i != (ac - 1) && av[++(f->i)])
	{
		if ((check_line(av[f->i])) && f->ccc &&
		(a->next = malloc(sizeof(t_lst))) && (f->cc++))
			a = a->next;
		f->i = help_main(av, &a, &f, &root_a);
	}
	return (main_for_norm(a, root_a, f));
}

int			main_for_norm(t_lst *a, t_lst *root_a, t_help *f)
{
	f->size = f->cc;
	if (root_a == NULL)
	{
		free(f);
		return (0);
	}
	if (!(is_overint(root_a)))
	{
		free(f);
		free_list2(root_a);
		return (display_error(0));
	}
	if (!check_massive(root_a))
	{
		free_list2(root_a);
		free(f);
		return (display_error(0));
	}
	return (make_TwoWay_list(root_a, f, 0));
}