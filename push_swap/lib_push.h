/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:34:51 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/13 22:50:00 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>



typedef struct      slist
{
	struct slist	*next;
	int				value;
}					t_list;

void				ft_putstr(char const *s);
int                 first_check(char **argv, int argc);
long long int       ft_atoi(const char *str);
int					make_list_a(int argc, long long int arr[argc], char *inst);
int     			push_in_b(t_list **b, t_list **a, t_list **root_b, t_list **root_a);