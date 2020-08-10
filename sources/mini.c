/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:05:40 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/10 22:46:02 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		all_free(t_list *root_a, t_list *root_b)
{
	free_list1(root_a);
	free_list1(root_b);
}

void		for_make(t_help **p)
{
	(*p)->q = 0;
	(*p)->w = 0;
	(*p)->c = 0;
}

int			help_first_check(char **argv, int i, int k, int g)
{
	while (argv[i][k] == ' ' || argv[i][k] == '\t' || argv[i][k] == '\n')
		k++;
	if ((argv[i][k] == '+' || argv[i][k] == '-') &&
	(argv[i][k + 1] >= '0' && argv[i][k + 1] <= '9'))
	{
		k++;
		while (argv[i][k] >= '0' && argv[i][k] <= '9')
			k++;
		if (argv[i][k] != ' ' && argv[i][k] != '\0' &&
		argv[i][k] != 't' && argv[i][k] != '\n')
			return (0);
	}
	else if ((argv[i][k] == '+' || argv[i][k] == '-') &&
	(argv[i][k + 1] < '0' || argv[i][k + 1] > '9'))
		return (0);
	else if (argv[i][k] >= '0' && argv[i][k] <= '9')
	{
		if ((k = help_first_check_con(argv, i, k)) == 0)
			return (0);
	}
	else if ((argv[i][k] < '0' || argv[i][k] > '9') && argv[i][k] != '\0')
		return (0);
	return (k - g);
}

int			help_first_check_con(char **argv, int i, int k)
{
	while (argv[i][k] >= '0' && argv[i][k] <= '9')
		k++;
	if (argv[i][k] != ' ' && argv[i][k] != '\t' &&
	argv[i][k] != '\n' && argv[i][k] != '\0')
		return (0);
	return (k);
}
