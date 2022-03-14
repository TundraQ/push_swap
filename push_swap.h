/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:24:55 by azane             #+#    #+#             */
/*   Updated: 2022/03/14 20:11:52 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_dblist
{
	t_node			*head;
	int				size;
}	t_dblist;

void				ft_init_list(t_dblist *lst);
void				ft_push_front_list(t_dblist *lst, int num);
void				ft_pop_front_list(t_dblist *lst);
void				ft_rotate_up_list(t_dblist *lst);
void				ft_rotate_down_list(t_dblist *lst);
void				ft_swap_list(t_dblist *lst);
void				ft_clear_list(t_dblist *lst);

typedef struct s_stack
{
	t_dblist		lst;
	char			type;
}	t_stack;

typedef struct s_stack_iterator
{
	t_node			*node;
	t_node			*head;
}	t_stack_iterator;

void				ft_stiter_next(t_stack_iterator *it);
int					ft_stiter_value(t_stack_iterator *it);
int					ft_stiter_equal(t_stack_iterator *it1,
						t_stack_iterator *it2);
t_stack_iterator	ft_stack_begin(t_stack *stack);
t_stack_iterator	ft_stack_end(t_stack *stack);

int					ft_get_min_index(t_stack *stack);
void				ft_init_stack(t_stack *stack, char name);
void				ft_push_stack(t_stack *stack, int num);
void				ft_pop_stack(t_stack *stack);
void				ft_push_from_to(t_stack *from, t_stack *to);
void				ft_rotate_up_stack(t_stack *stack);
void				ft_rotate_down_stack(t_stack *stack);
void				ft_rotate_stacks(t_stack *a, t_stack *b, char side);
void				ft_swap_stack(t_stack *stack);
void				ft_clear_stack(t_stack *stack);
int					ft_stack_top(t_stack *stack);
int					ft_stack_size(t_stack *stack);

int					ft_min(int a, int b);
int					ft_min_oper_for_elem(t_stack *a, t_stack *b,
						int index, int num);
int					ft_sort_3elem(t_stack *stack);
int					ft_optimize_top_less(t_stack *stack);
int					ft_lst_get_median(t_dblist *not_empty_list, int count);
int					ft_stack_push_mid_less(t_stack *from,
						t_stack *to, int count);
int					ft_stack_push_mid_bigger(t_stack *from,
						t_stack *to, int count);
void				ft_sort_top_less(t_stack *main, t_stack *_help, int count);
int					ft_sort_3_top_bigger(t_stack *main, t_stack *_help);
int					ft_sort_33_top_bigger(t_stack *main, t_stack *_help);
int					ft_sort_3_top_less(t_stack *main, t_stack *_help);
int					ft_sort_33_top_less(t_stack *main, t_stack *_help);
void				ft_stack_push_nelem(t_stack *from, t_stack *to, int count);
int					ft_optimize_top_bigger(t_stack *stack);
void				ft_sort_top_bigger(t_stack *main,
						t_stack *_help, int count);

int					*ft_get_lis(t_stack *stack, int *size);
int					ft_check_arg(char *argv);
int					*ft_get_best_lis(t_stack *stack, int *size);
int					ft_sort_5elem(t_stack *a, t_stack *b);
int					ft_find_min(t_stack *stack);
int					ft_find_max(t_stack *stack);
void				ft_starting_position(t_stack *a, t_stack *b);
void				ft_sort_stack(t_stack *a, t_stack *b);
int					ft_little_sort(t_stack *a, t_stack *b);
int					ft_find_best_place(t_stack *stack, int num);
void				ft_push_ab_index(t_stack *a,
						t_stack *b, int index, int num);
void				ft_starting_position(t_stack *a, t_stack *b);
int					ft_check_arg(char *argv);
#endif
