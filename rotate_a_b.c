/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:56:31 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/14 23:03:00 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int		rotate_a(t_list **root_a, t_list **a)
{
	t_list *buff;
	t_list *buff2;

	if (*(root_a) == NULL)
		return (0);
	buff = malloc(sizeof(t_list));
	buff2 = malloc(sizeof(t_list));
	buff->value = 
}