/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:24:55 by azane             #+#    #+#             */
/*   Updated: 2022/02/26 22:24:43 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
};

typedef struct s_node t_node;

struct dblist
{
	t_node		*head;
	unsigned	size;
};

typedef struct dblist t_dblist;

void	ft_init_list(t_dblist *lst);
void	ft_push_front_list(t_dblist *lst, int num);
void	ft_pop_front_list(t_dblist *lst);
void	ft_rotate_up_list(t_dblist *lst);
void	ft_rotate_down_list(t_dblist *lst);
void	ft_swap_list(t_dblist *lst);
void	ft_clear_list(t_dblist *lst);

struct s_stack
{
	t_dblist	lst;
};

typedef struct s_stack t_stack;

void	ft_init_stack(t_stack *stack);
void	ft_push_stack(t_stack *stack, int num);
void	ft_pop_stack(t_stack *stack);
void	ft_rotate_up_stack(t_stack *stack);
void	ft_rotate_down_stack(t_stack *stack);
void	ft_swap_stack(t_stack *stack);
void	ft_clear_stack(t_stack *stack);

int		ft_find_min(t_stack *stack);
int		ft_find_max(t_stack *stack);
void	ft_starting_position(t_stack *a, t_stack *b);


#endif
