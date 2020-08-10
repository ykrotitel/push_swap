/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:34:51 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/10 21:30:06 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_H
# define LIB_PUSH_H

# include <libc.h>
# include "libft.h"
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct		s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				value;
}					t_list;

typedef struct		s_lst
{
	struct s_lst	*next;
	long			value;
}					t_lst;

typedef	struct		s_help
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
	int				ccc;
	int				tmp;
	int				f;
	int				ff;
	int				fff;
	int				sec_tmp;
	char			*inst;
	int				i;
	int				q;
	int				w;
	t_list			*a;
	t_list			*b;
	t_list			*root_a;
	t_list			*root_b;
	t_list			*t3;
	int				size;
	int				chunk_size;
	int				up;
	int				down;
	int				max_b;
}					t_help;

int					first_check(char **argv, int argc);
int					make_sort(t_list *a, t_list *root_a, char *inst);
int					make_list_a(int argc, long long int arr[argc], char *inst);
int					swap(t_list **a, t_list **b,
t_list **root_a, t_list **root_b);
int					reverse(t_list **a, t_list **b,
t_list **root_a, t_list **root_b);
int					reverse_a(t_list **a, t_list **root_a, int t);
int					reverse_b(t_list **b, t_list **root_b, int t);
int					swap(t_list **a, t_list **b, t_list **root_a,
t_list **root_b);
int					swap_in_b(t_list **root_b, t_list **b);
int					swap_in_a(t_list **root_a, t_list **a);
int					rotate(t_list **root_a, t_list **root_b);
int					rotate_a(t_list **root_a);
int					rotate_b(t_list **root_b);
int					push_numbers_in_b(t_list *a, t_list *root_a, t_help *f);
void				take_min_mid_max(t_list *a, t_list *root_a,
int cc, t_help *f);
t_list				*sort_stack_a(t_list **root_a, t_list **a, t_help *f);
t_list				*rewrite(t_list *buff);
int					check_min_max(int value, t_help *f);
int					push_b(t_list **root_b, t_list **root_a);
int					push_a(t_list **root_a, t_list **root_b);
int					check_rb(t_list **root_b);
int					check_ra(t_list *root_a);
int					check_rrb(t_list **b, t_list **root_b);
int					check_rra(t_list **a, t_list **root_a);
int					swap_b_continue(t_list **root_b, t_list *root);
int					swap_a_continue(void);
int					check_argv(char *s);
int					display_error(int a);
int					make_sort_continue(t_list *b, t_list *root_b,
t_list *root_a);
int					main_sort(t_help *p);

int					checker_swap_a(t_list **root_a, t_list **a);
int					checker_swap_b(t_list **root_b, t_list **b);
int					checker_swap(t_list **a, t_list **b,
t_list **root_a, t_list **root_b);
int					checker_rotate_a(t_list **root_a);
int					checker_rotate_b(t_list **root_b);
int					checker_rotate(t_list **root_a, t_list **root_b);
int					checker_push_a(t_list **root_a, t_list **root_b);
int					checker_push_b(t_list **root_b, t_list **root_a);
int					checker_reverse_a(t_list **a, t_list **root_a);
int					checker_reverse_b(t_list **b, t_list **root_b);
int					checker_reverse(t_list **a, t_list **b,
t_list **root_a, t_list **root_b);
int					check_massive(t_lst *root_a);
int					check_stack_a(t_list *root_a);
int					main_sort_second(t_help *p);
int					ft_check_data(t_list *root_a);
void				print_a(t_lst *root_a);
void				print_b(t_lst *root_b);
int					help_rotate(t_list *tmp, int c);
void				for_make(t_help **p);
int					help_main(char **av, t_lst **a,
t_help **f, t_lst **root_a);
int					main_continue(t_list *a, t_list *root_a, t_help *f);
void				for_take_mmm(t_help **f, int cc, t_list *buff);
void				make_first_if(t_help **f, t_list *buff, t_list *root_buff);
void				make_first_else(t_help **f, t_list *buff);
void				second_step_while(t_help **f, t_list **root_a,
t_list **a, t_list **root_b);
void				second_step_secondwhile(t_help **f, t_list **root_a,
t_list **root_b, t_list **a);
int					is_overint(t_lst *root_a);
void				helper_while(t_list **buff, t_help **f,
t_list **root_a, t_list **a);
int					help_each_check(t_list *aa_r, char *inst);
int					help_first_check(char **argv, int i, int k, int g);
void				all_free(t_list *root_a, t_list *root_b);
void				for_make(t_help **p);
int					help_first_check_con(char **argv, int i, int k);
int					main_for_norm(t_lst *a, t_lst *root_a, t_help *f);
void				first_takeminmax(t_help **f, t_list *buff);
void				sort_only_2_3(t_list **root_a, t_list **a, t_help *f);
void				right_sort_3(t_list *buff, t_list **root_a,
t_list **a, t_help *f);
int					check_line(char *line);
void				sort_only_2_3(t_list **root_a, t_list **a, t_help *f);
void				right_sort_3(t_list *buff, t_list **root_a,
t_list **a, t_help *f);
void				for_f(t_help **f, t_lst **root_a);
void				help_for_help(t_lst **a, t_help **f, t_lst **root_a);
int					help_for_help_k(char **av, t_help **f);
int					check_each_inst(char *inst);
void				help_for_ps_main(t_lst **root_a, t_lst **a, t_help **f);
void				print(t_list *root_a);
int					main_continue(t_list *a, t_list *root_a, t_help *f);
void				free_list1(t_list *root_a);
void				free_list2(t_lst *root_a);
int					check_instruction(t_list *aa, t_list *aa_r);
int					each_check_inst(int i, char *inst);
int					another_check(t_lst *root_a, t_help *f, t_lst *a);

/* NEW ALGHORITM */
int					make_TwoWay_list(t_lst *root_buff, t_help *f, int t);
int					find_chunk(t_help *f, t_list *a, t_list *root_a);
void				MainSortChunk(t_help *f, t_list *root_a, t_list *a);
int					TakeNumberOperationUp(t_list *root_a, int min, int max);
int					TakeNumberOperationDown(t_list *root_a, int min, int max);
void				MakeMoreRotatePush(t_list **root_b, t_help **f, t_list **root_a);
void				MakeMoreReversePush(t_list **root_b, t_help **f, t_list **root_a, t_list **a);
int					TakeNumberOperationUpB(t_list *root_b, int value, t_help *f);
int					TakeNumberOperationDownB(t_list *root_b, int value, t_help *f);
int					CaseBiggerRoot(t_list *root_b, int value, t_help *f);
int					CaseBiggerValue(t_list *root_b, int value, t_help *f);
#endif
