/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 15:12:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/09 19:51:23 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		for_f(t_help **f, t_lst **root_a)
{
	(*f)->i = 1;
	(*f)->cc = 1;
	(*f)->ccc = 0;
	(*root_a) = NULL;
}

int			help_for_help_k(char **av, t_help **f)
{
	if (av[(*f)->i][0] == '-' || av[(*f)->i][0] == '+')
		return (1);
	return (0);
}

void		help_for_help(t_lst **a, t_help **f, t_lst **root_a)
{
	if ((*f)->ccc == 0)
	{
		(*a) = malloc(sizeof(t_lst));
		(*f)->ccc = 1;
		(*root_a) = (*a);
	}
}

int			check_each_inst(char *inst)
{
	int	i;

	i = 0;
	while (inst[i] != '\0')
	{
		while (inst[i] != '\n')
		{
			if (inst[i] == 'p' && (inst[i + 1] == 'a' ||
			inst[i + 1] == 'b'))
				i += 2;
			else if (inst[i] == 'r' && inst[i + 1] == 'r' &&
			(inst[i + 2] == 'a' || inst[i + 2] == 'b' || inst[i + 2] == 'r'))
				i += 3;
			else if (inst[i] == 's' && (inst[i + 1] == 'a' ||
			inst[i + 1] == 'b' || inst[i + 1] == 's'))
				i += 2;
			else if (inst[i] == 'r' && (inst[i + 1] == 'a' ||
			inst[i + 1] == 'b' || inst[i + 1] == 'r'))
				i += 2;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void		help_for_ps_main(t_lst **root_a, t_lst **a, t_help **f)
{
	(*a)->value = 0;
	(*root_a) = (*a);
	(*f)->ccc = 1;
	(*a)->next = NULL;
}
