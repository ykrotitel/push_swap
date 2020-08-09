/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:08:19 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/09 20:19:13 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"


void		free_list1(t_list *root_a)
{
	t_list	*tmp;

	while (root_a != NULL)
	{
		tmp = root_a;
		root_a = root_a->next;
		free(tmp);
	}
}

void		free_list2(t_lst *root_a)
{
	t_lst	*tmp;

	while (root_a != NULL)
	{
		tmp = root_a;
		root_a = root_a->next;
		free(tmp);
	}
}

int		check_instruction(t_list *aa, t_list *aa_r)
{
	char	*inst;
	char	buff;
	int		a;
	int		i;

	i = 0;
	if (!(inst = malloc(sizeof(char) * 20000)))
	{
		free_list1(aa_r);
		return (display_error(0));
	}
	while ((a = read(0, &buff, 1)) > 0)
	{
		inst[i] = buff;
		i++;
		if (buff == '\n')
		{
			if ((each_check_inst(i, inst)) == 0)
				return (help_each_check(aa_r, inst));
		}
	}
	inst[i] = '\0';
	return (make_sort(aa, aa_r, inst));
}

int		help_each_check(t_list *aa_r, char *inst)
{
	free_list1(aa_r);
	free(inst);
	return (display_error(1));
}

int		each_check_inst(int i, char *inst)
{
	int j;

	j = i;
	j -= 2;
	if (inst[j] == 'r' || inst[j] == 'b' || inst[j] == 'a')
	{
		if (inst[j - 1] == 'r' && inst[j - 2] == 'r' &&
		((j - 2) == 0 || inst[j - 3] == '\n'))
			return (1);
	}
	if (inst[j] == 'r' || inst[j] == 'a' || inst[j] == 'b')
	{
		if (inst[j - 1] == 'r' && ((j - 1) == 0 || inst[j - 2] == '\n'))
			return (1);
	}
	if (inst[j] == 'a' || inst[j] == 'b')
	{
		if ((inst[j - 1] == 's' || inst[j - 1] == 'p') &&
		((j - 1) == 0 || inst[j - 2] == '\n'))
			return (1);
	}
	if (inst[j] == 's' && inst[j - 1] == 's' &&
	((j - 1) == 0 || inst[j - 2] == '\n'))
		return (1);
	return (0);
}