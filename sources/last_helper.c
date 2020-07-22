/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:26:53 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/22 21:08:25 by acarlett         ###   ########.fr       */
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

void		for_make(t_help **p)
{
	(*p)->q = 0;
	(*p)->w = 0;
	(*p)->c = 0;
}

int			help_main(char **av, int i, t_list **a)
{
	int k;
	int j;

	k = 0;
	j = 1;
	if (av[i][k] == '-'|| av[i][k] == '+')
	{
		k++;
		printf ("av[i] = %s\n", av[i]);
		av[i]++;
		j = (av[i][k - 1] = '-' ? -1 : 1);
	}
	(*a)->value = ft_atoi(av[i]);
	(*a)->value = (*a)->value * j;
	while (av[i][k] == ' ' && av[i][k])
		k++;
	while (av[i][k] >= '0' && av[i][k] <= '9' && av[i][k])
		k++;
	while ((av[i][k] < '0' || av[i][k] > '9') && av[i][k])
		k++;
	if (av[i][k])
	{
		av[i] += k;
		i--;
	}
	return (i);
}

int			first_check(char **argv)
{
	int		i;
	int		k;

	i = 1;
	k = 0;
	while (argv[i])
	{
		while (argv[i][k])
		{
			if ((argv[i][k] < '0' || argv[i][k] > '9') &&
			argv[i][k] != ' ' && argv[i][k] != '\t')
			{
				if (argv[i][k] == '-' || argv[i][k] == '+')
				{
					while (argv[i][k] < '0' || argv[i][k] > '9')
						k++;
					if (argv[i][k] == ' ' || argv[i][k] == '\t')
						return (0);
				}
			}
			else
				k++;
		}
		k = 0;
		i++;
	}
	return (1);
}
