/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:08:19 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/15 17:06:51 by acarlett         ###   ########.fr       */
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
	root_a = NULL;
	tmp = NULL;
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
	root_a = NULL;
	tmp = NULL;
}

int			check_instruction(t_list *aa, t_list *aa_r, t_help *f)
{
	char	*inst;
	char	buff;
	int		a;
	int		i;

	i = 0;
	inst = malloc(sizeof(char) * 20000);
	while ((a = read(0, &buff, 1)) > 0)
	{
		inst[i] = buff;
		i++;
		if (buff == '\n')
		{
			if ((each_check_inst(i, inst)) == 0)
				return (help_each_check(aa_r, inst, f));
		}
	}
	inst[i] = '\0';
	return (make_sort(aa, aa_r, inst, f));
}

int			help_each_check(t_list *aa_r, char *inst, t_help *f)
{
	free_list1(aa_r);
	free(inst);
	free(f);
	return (display_error(1));
}

int			each_check_inst(int i, char *inst)
{
	int j;

	j = i;
	j -= 2;
	if (inst[j] == 'r' || inst[j] == 'b' || inst[j] == 'a')
		if (((j - 2) == 0 || ((j - 3) >= 0 && inst[j - 3] == '\n')) &&
			inst[j - 1] == 'r' && inst[j - 2] == 'r')
			return (1);
	if (inst[j] == 'r' || inst[j] == 'a' || inst[j] == 'b')
		if (((j - 1) == 0 || ((j - 2) >= 0 &&
		inst[j - 2] == '\n')) && inst[j - 1] == 'r')
			return (1);
	if (inst[j] == 'a' || inst[j] == 'b')
		if (((j - 1) == 0 || ((j - 2) >= 0 && inst[j - 2] == '\n')) &&
		(inst[j - 1] == 's' || inst[j - 1] == 'p'))
			return (1);
	if (((j - 1) == 0 ||
	((j - 2) >= 0 && inst[j - 2] == '\n')) &&
	inst[j] == 's' && inst[j - 1] == 's')
		return (1);
	return (0);
}
