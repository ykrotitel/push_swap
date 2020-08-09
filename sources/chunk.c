/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:18:52 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/08 17:56:28 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		find_chunk(t_help *f, t_list *a, t_list *root_a)
{
	if (f->size <= 50)
		f->chunk_size = 10;
	else if (f->size > 50 && f->size < 100)
		f->chunk_size = 15;
	else if (f->size >= 100 && f->size < 200)
		f->chunk_size = 20;
	else if (f->size >= 200 && f->size < 300)
		f->chunk_size = 30;
	else if (f->size >= 300 && f->size < 400)
		f->chunk_size = 40;
	else if (f->size >= 400 && f->size < 500)
		f->chunk_size = 45;
	else if (f->size >= 500)
		f->chunk_size = 50;	
	take_min_mid_max(a, root_a, f->cc, f);
	return (0);
}