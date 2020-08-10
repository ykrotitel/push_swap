/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_rotate_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:02:42 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/10 22:07:20 by acarlett         ###   ########.fr       */
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
	/*						^
							|
		Расстояние до подходящего места сверху в стеке В
	*/
	down = TakeNumberOperationDownB((*root_b), (*root_a)->value, (*f));
	/*						^
							|
		Расстояние до подходящего места снизу в стеке B
	*/
	if (up < down)
		while ((up--) >= 0) /*	ROTATE_B пока не дойдем	*/
			rotate_b(root_b);/*	до необходимого места	*/
	else
		while ((down--) >= 0)
			reverse_b(&b, root_b, 0);/* REVERSE_B пока не дойдем до необходимого места */
	// push_b();
}

void		CheckGoodPlaceToPush(t_list **root_a, t_list **root_b, t_help **f, int ff)
{
	if ((*root_b) != NULL)
	if ((CheckSortStackB((*root_b), (*root_a)->value)))/* Если стек отсортирован в убывающем порядке*/
		OnlyPushB(root_a, root_b, f); /*Просто находим для него место и пушим туда*/
	// else /*
	// 		Иначе Сортируем стек В, находим подходящее
	// 			место для root_a->value и пушим
	// 	*/
	// 		// SortingB_Push();
	return ;
}

void		MakeMoreRotatePush(t_list **root_b, t_help **f, t_list **root_a)
{
	while ((*root_a) != NULL)
	{
		if ((*root_a)->value >= (*f)->min && (*root_a)->value <= (*f)->max)
		{
			CheckGoodPlaceToPush(root_a, root_b, f, 0); 
			/*
				При нахождении первого элемента чанка
				ищем для него место в стеке В и пушим
			*/
		}
		else
		{
			/*
				Иначе делаем ROTATE_A пока не найдем нужный элемент
			*/
			rotate_a(root_a);
			write (1, "ra\n", 3);
		}
	}
	return ;
}

void		MakeMoreReversePush(t_list **root_b, t_help **f, t_list **root_a, t_list **a)
{
	int min;
	int max;

	min = (*f)->min;
	max = (*f)->max;
	while ((*root_a) != NULL)
	{
		if ((*root_a)->value >= min && (*root_a)->value <= max)
			CheckGoodPlaceToPush(root_a, root_b, f, 1);
		reverse_a(a, root_a, 0);
		write (1, "rra\n", 4);
	}
	return ;
}