/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_rotate_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:02:42 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/13 03:43:13 by acarlett         ###   ########.fr       */
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
	write (1, "GOV", 3);
	printf ("up_B - %d, down_B - %d\n", up, down);
	write (1, "NO\n", 3);
	if (up <= down)
		while ((up--) > 0) 	/*	ROTATE_B пока не дойдем	*/
			new_rotate(root_b) && write (1, "rb\n", 3);	/*	до необходимого места	*/
	else
		while ((down--) > 0)
			new_reverse(root_b) && write (1, "rrb\n", 4);/* REVERSE_B пока не дойдем до необходимого места */
	print_b((*root_b));
	new_push(root_a, root_b) && write (1, "pb\n", 3);
	print_b((*root_b));
}

void		CheckGoodPlaceToPush(t_list **root_a, t_list **root_b, t_help **f, int ff)
{
	if ((*root_b) != NULL)
	{
		TakeMinMaxValueB((*root_b), f);
		if ((CheckSortStackB((*root_b), (*root_a)->value)))
		{
			printf ("root_a->value = %d\n", (*root_a)->value);
			OnlyPushB(root_a, root_b, f);
		}
		else
		{
			new_swap(root_b) && write (1, "sb\n", 3);
			print_b((*root_b));
		}
	}
	else
	{
		new_push(root_a, root_b) && write (1, "pb\n", 3);
		print_b((*root_b));
	}
	return ;
}

void		MakeMoreRotatePush(t_list **root_b, t_help **f, t_list **root_a)
{
	while ((*root_a) != NULL)
	{
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

void		MakeMoreReversePush(t_list **root_b, t_help **f, t_list **root_a, t_list **a)
{
	int min;

	min = (*f)->min;
	while ((*root_a) != NULL)
	{
		if ((*root_a)->value >= (*f)->local_min && (*root_a)->value <= (*f)->local_max)
			CheckGoodPlaceToPush(root_a, root_b, f, 1);
		else
		{
			reverse_a(a, root_a, 0);
			write (1, "rra\n", 4);
		}
	}
	return ;
}

/*
			0
2  (rrb)	3 
1			2
3			1


*/