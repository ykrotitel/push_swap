/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:26:53 by acarlett          #+#    #+#             */
/*   Updated: 2020/09/09 21:56:23 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int			help_rotate(t_list *tmp, int c)
{
	t_list	*buff;
	int		i;

	buff = tmp;
	i = 0;
	while (tmp->value != c)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int			continue_help_main(int k, t_lst **root_a, t_help **f)
{
	if (k > 11)
	{
		free_list2((*root_a));
		write(2, "Error\n", 6);
		exit(0);
	}
	return ((*f)->i);
}

int			help_main(char **av, t_lst **a, t_help **f, t_lst **root_a)
{
	int k;
	int j;

	j = 1;
	k = help_for_help_k(av, f);
	if ((check_line(av[(*f)->i])))
	{
		help_for_help(a, f, root_a);
		(*a)->value = ft_atoi(av[(*f)->i]);
		(*a)->value = (*a)->value * j;
		while (av[(*f)->i][k] == ' ' && av[(*f)->i][k])
			k++;
		if (av[(*f)->i][k] == '-' || av[(*f)->i][k] == '+')
			k++;
		while (av[(*f)->i][k] >= '0' && av[(*f)->i][k] <= '9' && av[(*f)->i][k])
			k++;
		if (av[(*f)->i][k])
		{
			av[(*f)->i] += k;
			((*f)->i)--;
		}
		(*a)->next = NULL;
	}
	return (continue_help_main(k, root_a, f));
}

int			first_check(char **argv, int argc)
{
	int		i;
	int		k;
	int		g;

	i = 1;
	k = 0;
	g = 0;
	while (argc - 1)
	{
		while (argv[i][k] != '\0')
		{
			if (!(g = help_first_check(argv, i, k, k)))
				return (0);
			else
				k += g;
		}
		i++;
		k = 0;
		argc--;
	}
	return (4);
}

int			is_overint(t_lst *root_a)
{
	while (root_a != NULL)
	{
		if (root_a->value > MAX_INT || root_a->value < MIN_INT)
			return (0);
		root_a = root_a->next;
	}
	return (1);
}
