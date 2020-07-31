/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:26:53 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/31 16:16:13 by acarlett         ###   ########.fr       */
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

int			help_main(char **av, int i, t_list **a)
{
	int k;
	int j;

	k = 0;
	j = 1;
	if (av[i][k] == '-' || av[i][k] == '+')
		k++;
	(*a)->value = ft_atoi(av[i]);
	(*a)->value = (*a)->value * j;
	while (av[i][k] == ' ' && av[i][k])
		k++;
	if (av[i][k] == '-' || av[i][k] == '+')
		k++;
	while (av[i][k] >= '0' && av[i][k] <= '9' && av[i][k])
		k++;
	if (av[i][k])
	{
		av[i] += k;
		i--;
	}
	return (i);
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

void		free_list(t_list *root_a)
{
	t_list	*tmp;

	while (root_a != NULL)
	{
		tmp = root_a;
		root_a = root_a->next;
		free(tmp);
	}
}

int			is_overint(t_list *root_a)
{
	while (root_a != NULL)
	{
		if (root_a->value > MAX_INT || root_a->value < MIN_INT)
			return (0);
		root_a = root_a->next;
	}
	return (1);
}
