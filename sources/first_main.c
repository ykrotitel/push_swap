/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:59:03 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/07 14:58:46 by acarlett         ###   ########.fr       */
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

int		check_instruction(t_list *aa, t_list *aa_r)
{
	char	*inst;
	char	buff;
	int		a;
	int		i;

	i = 0;
	if (!(inst = malloc(sizeof(*inst) * 20000)))
	{
		free_list(aa_r);
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

int		get_array(int argc, char **argv)
{
	t_list	*a;
	t_list	*root_a;
	t_help	*f;

	if (argc == 1)
		return (0);
	if (!(first_check(argv, argc)))
		return (display_error(0));
	f = malloc(sizeof(t_help));
	f->i = 1;
	f->cc = 1;
	f->ccc = 0;
	root_a = NULL;
	if (check_line(argv[f->i]))
	{
		a = malloc(sizeof(t_list));
		a->value = 0;
		root_a = a;
		f->ccc = 1;
		a->next = NULL;
	}
	f->i = help_main(argv, &a, &f, &root_a);
	while (f->i != (argc - 1) && argv[++(f->i)])
	{
		if ((check_line(argv[f->i])) && f->ccc && (a->next = malloc(sizeof(t_list))) && (f->cc++))
			a = a->next;
		f->i = help_main(argv, &a, &f, &root_a);
	}
	f->size = f->cc;
	if (root_a == NULL)
	{
		free(f);
		return (0);
	}
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
