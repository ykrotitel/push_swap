/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:39:47 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/13 23:18:54 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push.h"

int     push_in_b(t_list **b, t_list **a, t_list **root_b, t_list **root_a)
{
    t_list *buff;
    t_list *buff_root;

    if((*b) == (*root_b))
    {
        write (1, "F\n", 2);
        (*b)->value = (*a)->value;
        (*b)->next = malloc(sizeof(t_list));
        (*b) = (*b)->next;
        (*b)->next = NULL;
    }
    else
    {
        write (1, "S\n", 2);
        buff = malloc(sizeof(t_list));
        buff_root = buff;
        buff->value = (*a)->value;
        buff->next = (*root_b);
        (*root_b) = buff_root;
    }
    (*root_a) = (*a)->next;
    free(*a);
    (*a) = (*root_a);
    return(1);
}