/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 15:12:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/07 15:13:08 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		for_r(t_help **f)
{
	(*f) = malloc(sizeof(t_help));
	(*f)->i = 1;
	(*f)->cc = 1;
	(*f)->ccc = 0;
}