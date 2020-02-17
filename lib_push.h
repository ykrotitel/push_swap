/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:34:51 by acarlett          #+#    #+#             */
/*   Updated: 2020/02/15 22:02:30 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>



typedef struct      slist
{
	struct slist	*next;
	int				value;
}					t_list;

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
void				ft_putstr(char const *s);
long long int       ft_atoi(const char *str);
int					ft_isalpha(char c);