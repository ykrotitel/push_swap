/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_rotate_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:02:42 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/14 19:42:17 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int		CheckSortStackB(t_list *root_b, int value)
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

void		OnlyPushB(t_list **root_a, t_list **root_b, t_help **f)
{
	int		up;
	int		down;
	t_list	*b;

	b = (*root_b);
	while (b->next != NULL)
		b = b->next;
	up = TakeNumberOperationUpB((*root_b), (*root_a)->value, (*f));
	down = TakeNumberOperationDownB((*root_b), (*root_a)->value, (*f));
	if (up <= down)
		while (up > 0)
		{
			up--;
			new_rotate(root_b) && write (1, "rb\n", 3);
		}
	else
		while (down > 0)
		{
			down--;
			new_reverse(root_b) && write (1, "rrb\n", 4);
		}
	new_push(root_a, root_b) && write (1, "pb\n", 3);
	TakeMinMaxValue((*root_a), f);
	if ((*f)->local_max < (*f)->min)
	{
		(*f)->local_min = (*f)->min;
		(*f)->local_max = (*f)->min + (*f)->chunk_size;
	}

}

void		CheckGoodPlaceToPush(t_list **root_a, t_list **root_b, t_help **f, int ff)
{
	if ((*root_b) != NULL)
	{
		TakeMinMaxValueB((*root_b), f);
		if ((CheckSortStackB((*root_b), (*root_a)->value)))
		{
			OnlyPushB(root_a, root_b, f);
		}
		else
		{
			new_swap(root_b) && write (1, "sb\n", 3);
		}
	}
	else
	{
		new_push(root_a, root_b) && write (1, "pb\n", 3);
		TakeMinMaxValue((*root_a), f);
		if ((*f)->local_max < (*f)->min)
		{
			(*f)->local_min = (*f)->min;
			(*f)->local_max = (*f)->min + (*f)->chunk_size;
		}

	}
	return ;
}

void		MakeMoreRotatePush(t_list **root_b, t_help **f, t_list **root_a)
{
	while ((*root_a) != NULL)
	{
		if (((*f)->min + (*f)->chunk_size) < (*f)->min)
		{
			TakeMinMaxValue((*root_a), f);
			(*f)->local_min = (*f)->min;
			(*f)->local_max = (*f)->min + (*f)->chunk_size;

		}
		if ((*root_a)->value >= (*f)->local_min && (*root_a)->value <= (*f)->local_max)
		{
			CheckGoodPlaceToPush(root_a, root_b, f, 0);
			return ;
		}
		else
			new_rotate(root_a) && write (1, "ra\n", 3);
	}
	return ;
}

void		MakeMoreReversePush(t_list **root_b, t_help **f, t_list **root_a)
{
	while ((*root_a) != NULL)
	{
		if (((*f)->min + (*f)->chunk_size) < (*f)->min)
		{
			TakeMinMaxValue((*root_a), f);
			(*f)->local_min = (*f)->min;
			(*f)->local_max = (*f)->min + (*f)->chunk_size;
		
		}
		if ((*root_a)->value >= (*f)->local_min && (*root_a)->value <= (*f)->local_max)
			CheckGoodPlaceToPush(root_a, root_b, f, 1);
		else
		{
			new_reverse(root_a);
			write (1, "rra\n", 4);
		}
	}
	return ;
}
