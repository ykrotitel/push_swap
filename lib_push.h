/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:34:51 by acarlett          #+#    #+#             */
/*   Updated: 2020/03/02 18:28:36 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_H
#define LIB_PUSH_H

#include <libc.h>

typedef struct      slist
{
	struct slist	*next;
	int				value;
}					t_list;

typedef	struct		shelp
{
	int				min;
	char			*minn;
	char			*f_min;
	int				mid;
	char			*midd;
	char			*f_mid;
	int				max;
	char			*maxx;
	char			*f_max;
	int				c;
	int				cc;
	int				tmp;
	int				f;
	int				ff;
	int				sec_tmp;
}					thelp;

int                 first_check(char **argv, int argc);
int					make_sort(t_list *a,t_list *root_a, char *inst);
int					make_list_a(int argc, long long int arr[argc], char *inst);
int					swap(t_list **a, t_list **b, t_list **root_a, t_list **root_b);
int     			push_in_a(t_list **b, t_list **a, t_list **root_b, t_list **root_a);
int     			push_in_b(t_list **b, t_list **a, t_list **root_b, t_list **root_a);
int					reverse(t_list **a, t_list **b, t_list **root_a, t_list **root_b);
int					reverse_a(t_list **a, t_list **root_a);
int					reverse_b(t_list **b, t_list **root_b);
int					swap(t_list **a, t_list **b, t_list **root_a, t_list **root_b);
int					swap_in_b(t_list **root_b, t_list **b);
int					swap_in_a(t_list **root_a, t_list **a);
int					rotate(t_list **root_a, t_list **root_b);
int					rotate_a(t_list **root_a);
int					rotate_b(t_list **root_b);
int					ft_putstr(char const *s);
long long int       ft_atoi(const char *str);
int					ft_isalpha(char c);
int					push_numbers_in_b(t_list *a, t_list *root_a, thelp *f);
int					numbers_of_different_various(t_list *root, int max, int min);
void				take_min_mid_max(t_list *a, t_list *root_a, int cc);
t_list				*sort_stack_a(t_list *root_a, t_list *a, thelp *f);
t_list				*rewrite(t_list *buff);
int					check_min_max(int value, thelp *f);

#endif