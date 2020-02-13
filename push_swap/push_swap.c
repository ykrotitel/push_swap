/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:59:03 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/13 20:19:59 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int     check_argv(char *s)
{
	int i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

int     first_check(char **argv, int argc)
{
	int i;

	i = 1;
	while((i < argc) && (check_argv(argv[i]) == 1))
		i++;
	if (i == argc)
		return (1);
	return (0);
}

int     display_error()
{   
	ft_putstr("Error\n");
	return (0);
}

int		check_each_inst(char *inst)
{
	int i;

	i = 0;
	while (inst[i] != '\0')
	{
		while (inst[i] != '\n')
		{
			if (inst[i] == 'p' && (inst[i + 1] == 'a' || inst[i + 1] == 'b'))
				i+=2;
			else if (inst[i] == 'r' && inst[i + 1] == 'r' && (inst[i + 2] == 'a' || inst[i + 2] == 'b' || inst[i + 2] == 'r'))
				i+=3;
			else if (inst[i] == 's' && (inst[i + 1] == 'a' || inst[i + 1] == 'b' || inst[i + 1] == 's'))
				i+=2;
			else if (inst[i] == 'r' && (inst[i + 1] == 'a' || inst[i + 1] == 'b' || inst[i + 1] == 'r'))
				i+=2;
			else
				return (0);	
		}
		i++;
	}
	return (1);
}

int     check_instruction(int argc, char **argv, long long int arr[argc])
{
	char	*inst;
	char	buff[1];
	int		a;
	int		i;
	
	i = 0;
	if (!(inst = malloc(sizeof(*inst) * 20000)))
		return(display_error());
	while ((a = read(0, buff, 1)) > 0)
	{
		inst[i] = buff[0];
		i++;
	}
	inst[i] = '\0';
	if (!(check_each_inst(inst)))
		return (display_error());
	make_list_a(argc, arr, inst);
	return (0);
}

int		get_array(int argc, char **argv)
{
	long long int	arr[argc];
	int 			i;

	i = 1;
	while(i != argc)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	check_instruction(argc, argv, arr);
	return (1);
}

int     main(int argc, char **argv)
{
	if (!(first_check(argv, argc)))
		return (display_error());
	get_array(argc, argv);
}