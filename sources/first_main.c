/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:59:03 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/21 17:57:22 by acarlett         ###   ########.fr       */
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

int		check_instruction(t_list *aa, t_list *aa_r)
{
	char	*inst;
	char	buff[1];
	int		a;
	int		i;

	i = 0;
	if (!(inst = malloc(sizeof(*inst) * 20000)))
	{
		ft_putstr("Error\n");
		return (0);
	}
	while ((a = read(0, buff, 1)) > 0)
	{
		inst[i] = buff[0];
		i++;
	}
	inst[i] = '\0';
	if (!(check_each_inst(inst)))
	{
		ft_putstr("Error  -->  Unreadble instruction\n");
		return (0);
	}
	make_sort(aa, aa_r, inst);
	return (0);
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
	if (!check_massive(root_a))
		return (display_error());
	check_instruction(a, root_a);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (!(first_check(argv)))
	{
		ft_putstr("Error\n");
		return (0);
	}
	get_array(argc, argv);
}
