/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:33:42 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/09 20:34:14 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		get_array(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*root_a;
	t_help	*f;

	f = malloc(sizeof(t_help));
	for_f(&f, &root_a);
	if (check_line(argv[f->i]))
	{
		a = malloc(sizeof(t_lst));
		a->value = 0;
		root_a = a;
		f->ccc = 1;
		a->next = NULL;
	}
	f->i = help_main(argv, &a, &f, &root_a);
	while (f->i != (argc - 1) && argv[++(f->i)])
	{
		if ((check_line(argv[f->i])) && f->ccc &&
		(a->next = malloc(sizeof(t_lst))) && (f->cc++))
			a = a->next;
		f->i = help_main(argv, &a, &f, &root_a);
	}
	f->size = f->cc;
	return (another_check(root_a, f, a));
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (!(first_check(argv, argc)))
		return (display_error(0));
	get_array(argc, argv);
}
