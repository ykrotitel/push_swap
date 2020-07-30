/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:59:03 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/30 18:03:41 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		check_each_inst(char *inst)
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

int		each_check_inst(int i, char *inst)
{
	int j;

	j = i;
	j -= 2;
	if (inst[j] == 'r' || inst[j] == 'b' || inst[j] == 'a')
	{
		if (inst[j - 1] == 'r' && inst[j - 2] == 'r' &&
		(inst[j - 3] == '\n' || (j - 2) == 0))
			return (1);
	}
	if (inst[j] == 'r' || inst[j] == 'a' || inst[j] == 'b')
	{
		if (inst[j - 1] == 'r' && (inst[j - 2] == '\n' || (j - 1) == 0))
			return (1);
	}
	if (inst[j] == 'a' || inst[j] == 'b')
	{
		if ((inst[j - 1] == 's' || inst[j - 1] == 'p') &&
		(inst[j - 2] == '\n' || (j - 1) == 0))
			return (1);
	}
	if (inst[j] == 's' && inst[j - 1] == 's' &&
	(inst[j - 2] == '\n' || (j - 1) == 0))
		return (1);
	return (0);
}

int		check_instruction(t_list *aa, t_list *aa_r)
{
	char	*inst;
	char	buff[1];
	int		a;
	int		i;

	i = 0;
	if (!(inst = malloc(sizeof(*inst) * 20000)))
	{
		free_list(aa_r);
		return (display_error(0));
	}
	while ((a = read(0, buff, 1)) > 0)
	{
		inst[i] = buff[0];
		i++;
		if (buff[0] == '\n')
		{
			if ((each_check_inst(i, inst)) == 0)
				return (help_each_check(aa_r, inst));
		}
	}
	inst[i] = '\0';
	return (make_sort(aa, aa_r, inst));
}

int		get_array(int argc, char **argv)
{
	t_list	*a;
	t_list	*root_a;
	int		i;

	i = 1;
	a = malloc(sizeof(t_list));
	root_a = a;
	i = help_main(argv, i, &a);
	while (i != (argc - 1))
	{
		i++;
		a->next = malloc(sizeof(t_list));
		a = a->next;
		i = help_main(argv, i, &a);
	}
	a->next = NULL;
	if (!(is_overint(root_a)) || !(check_massive(root_a)))
	{
		free_list(root_a);
		return (display_error(0));
	}
	check_instruction(a, root_a);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (!(first_check(argv, argc)))
	{
		ft_putstr("Error\n");
		return (0);
	}
	get_array(argc, argv);
}
