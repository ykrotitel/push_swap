/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:34:51 by acarlett          #+#    #+#             */
/*   Updated: 2020/09/10 20:46:48 by acarlett         ###   ########.fr       */
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
	int				min_b;
	int				local_min;
	int				max;
	int				max_b;
	int				local_max;
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
	int				mal;
	char			*ins;
}					t_help;

int					first_check(char **argv, int argc);
int					make_sort(t_list *root_a, char *inst, t_help *f);
int					make_list_a(int argc, long long int arr[argc], char *inst);
int					swap(t_list **root_a, t_list **root_b);
int					rotate(t_list **root_a, t_list **root_b);
int					reverse(t_list **root_a, t_list **root_b);
int					check_argv(char *s);
int					display_error(int a);
int					make_sort_continue(t_list *root_b, t_list *root_a);
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
int					help_rotate(t_list *tmp, int c);
void				for_make(t_help **p);
int					help_main(char **av, t_lst **a,
t_help **f, t_lst **root_a);
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
int					help_each_check(t_list *aa_r, char *inst, t_help *f);
int					help_first_check(char **argv, int i, int k, int g);
void				all_free(t_list *root_a, t_list *root_b);
void				for_make(t_help **p);
int					help_first_check_con(char **argv, int i, int k);
int					main_for_norm(t_lst *root_a, t_help *f);
void				sort_only_2_3(t_list **root_a, t_list **a, t_help *f);
void				right_sort_3(t_list *buff, t_list **root_a, t_help *f);
int					check_line(char *line);
void				sort_only_2_3_5(t_list **root_a, t_help *f);
void				for_f(t_help **f, t_lst **root_a);
void				help_for_help(t_lst **a, t_help **f, t_lst **root_a);
int					help_for_help_k(char **av, t_help **f);
int					check_each_inst(char *inst);
void				help_for_ps_main(t_lst **root_a, t_lst **a, t_help **f);
int					main_continue(t_list *root_a, t_help *f);
void				free_list1(t_list *root_a);
void				free_list2(t_lst *root_a);
int					check_instruction(t_list *aa_r, t_help *f);
int					each_check_inst(int i, char *inst);
int					another_check(t_lst *root_a, t_help *f);
void				second_step(t_list *root_a, t_help *f);
int					maketwowaylist(t_lst *root_buff, t_help *f, int t);
int					find_chunk(t_help *f, t_list *root_a);
void				takeminmaxvalue(t_list *root_a, t_help **f);
void				takeminmaxvalueb(t_list *root_a, t_help **f);
void				mainsortchunk(t_help *f, t_list **root_a);
int					takenumberoperationup(t_list *root_a, int min, int max);
int					takenumberoperationdown(t_list *root_a, int min, int max);
void				makemorerotatepush(t_list **root_b, t_help **f,
t_list **root_a);
void				makemorereversepush(t_list **root_b, t_help **f,
t_list **root_a);
int					takenumberoperationupb(t_list *root_b,
int value, t_help *f);
int					takenumberoperationdownb(t_list *root_b, int value,
t_help *f);
int					casebiggerroot(t_list *root_b, int value, t_help *f);
int					casebiggervalue(t_list *root_b, int value, t_help *f);
int					new_push(t_list **root_src, t_list **root_dest);
int					new_rotate(t_list **stack);
int					new_reverse(t_list **stack);
int					new_swap(t_list **stack);
void				checkgoodplacetopush(t_list **root_a, t_list **root_b,
t_help **f);
int					check_line(char *line);
void				privet(t_list **root_a, t_list **root_b, int com);
int					all_free_check(char *inst, t_help *f, t_list *aa_r);
void				privet_3(t_list **root_a, int com);

#endif
