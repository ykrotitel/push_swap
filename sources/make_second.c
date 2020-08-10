/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_second.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:08:48 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/10 22:47:52 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int			main_continue(t_list *a, t_list *root_a, t_help *f)
{
	if (!check_stack_a(root_a))
	{
		free_list1(root_a);
		free(f);
		return (0);
	}
	return (find_chunk(f, a, root_a));
}
