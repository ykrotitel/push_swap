/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:10:49 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/10 22:45:53 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		helper_while(t_list **buff, t_help **f, t_list **root_a, t_list **a)
{
	(*f)->ccc = (*buff)->value;
	(*f)->q = help_rotate((*root_a), (*f)->ccc);
	(*f)->w = (*f)->cc - (*f)->q;
	while ((*root_a)->value != (*f)->ccc)
		((*f)->w > (*f)->q ? reverse_a(a, root_a, 0) &&
	write(1, "rra\n", 4) : rotate_a(root_a) && write(1, "ra\n", 3));
}
