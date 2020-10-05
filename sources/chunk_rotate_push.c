/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_rotate_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:02:42 by acarlett          #+#    #+#             */
/*   Updated: 2020/09/10 18:02:21 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int			checksortstackb(t_list *root_b)
{
	t_list *buff;
	t_list *buff_next;

	buff = root_b;
	buff_next = buff->next;
	while ((buff_next != NULL) && (buff->value > buff_next->value))
	{
		buff = buff->next;
		buff_next = buff_next->next;
	}
	if (buff_next != NULL)
	{
		buff = buff->next;
		buff_next = buff_next->next;
		while ((buff_next != NULL) && (buff->value > buff_next->value))
		{
			buff = buff->next;
			buff_next = buff_next->next;
		}
	}
	if (buff_next != NULL)
		return (0);
	return (1);
}

void		onlypushb(t_list **root_a, t_list **root_b, t_help **f)
{
	int		up;
	int		down;

	up = takenumberoperationupb((*root_b), (*root_a)->value, (*f));
	down = takenumberoperationdownb((*root_b), (*root_a)->value, (*f));
	if (up <= down)
		while (up > 0)
		{
			up--;
			privet(root_a, root_b, 2);
		}
	else
		while (down > 0)
		{
			down--;
			privet(root_a, root_b, 4);
		}
	privet(root_a, root_b, 0);
	takeminmaxvalue((*root_a), f);
	if ((*f)->local_max < (*f)->min)
	{
		(*f)->local_min = (*f)->min;
		(*f)->local_max = (*f)->min + (*f)->chunk_size;
	}
}

void		checkgoodplacetopush(t_list **root_a, t_list **root_b,
t_help **f)
{
	if ((*root_b) != NULL)
	{
		takeminmaxvalueb((*root_b), f);
		if ((checksortstackb((*root_b))))
		{
			onlypushb(root_a, root_b, f);
		}
		else
			privet(root_a, root_b, 7);
	}
	else
	{
		privet(root_a, root_b, 0);
		takeminmaxvalue((*root_a), f);
		if ((*f)->local_max < (*f)->min)
		{
			(*f)->local_min = (*f)->min;
			(*f)->local_max = (*f)->min + (*f)->chunk_size;
		}
	}
	return ;
}

void		makemorerotatepush(t_list **root_b, t_help **f, t_list **root_a)
{
	while ((*root_a) != NULL)
	{
		if (((*f)->min + (*f)->chunk_size) < (*f)->min)
		{
			takeminmaxvalue((*root_a), f);
			(*f)->local_min = (*f)->min;
			(*f)->local_max = (*f)->min + (*f)->chunk_size;
		}
		if ((*root_a)->value >= (*f)->local_min &&
		(*root_a)->value <= (*f)->local_max)
		{
			checkgoodplacetopush(root_a, root_b, f);
			return ;
		}
		else
			privet(root_a, root_b, 3);
	}
	return ;
}

void		makemorereversepush(t_list **root_b, t_help **f, t_list **root_a)
{
	while ((*root_a) != NULL)
	{
		if (((*f)->min + (*f)->chunk_size) < (*f)->min)
		{
			takeminmaxvalue((*root_a), f);
			(*f)->local_min = (*f)->min;
			(*f)->local_max = (*f)->min + (*f)->chunk_size;
		}
		if ((*root_a)->value >= (*f)->local_min &&
		(*root_a)->value <= (*f)->local_max)
			checkgoodplacetopush(root_a, root_b, f);
		else
			privet(root_a, root_b, 5);
	}
	return ;
}
