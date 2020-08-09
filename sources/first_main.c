/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:59:03 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/09 20:36:40 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		another_check(t_lst *root_a, t_help *f, t_lst *a)
{
	if (root_a == NULL)
	{
		free(f);
		return (0);
	}
	if (!(is_overint(root_a)) || !(check_massive(root_a)))
	{
		free(f);
		free_list2(root_a);
		return (display_error(0));
	}
	free(f);
	make_TwoWay_list(root_a, f, 1);
	return (0);
}
