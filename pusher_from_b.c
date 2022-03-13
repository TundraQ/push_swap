/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_from_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 06:29:26 by azane             #+#    #+#             */
/*   Updated: 2022/03/13 06:47:48 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_norm
{
	int		count;
	int		best_place_index;
	char	stack_a;
	char	stack_b;
	int		tmp;
	int		i;
}	t_norm;

void	ft_same_direction(t_stack *a, t_stack *b, t_norm *norm)
{
	norm->tmp = ft_min(norm->count, norm->best_place_index);
	norm->i = 0;
	while (norm->i++ < norm->tmp)
		ft_rotate_stacks(a, b, norm->stack_a);
	norm->i = 0;
	if (norm->count > norm->tmp)
	{
		if (norm->stack_a == 'u')
			while (norm->i++ < (norm->count - norm->tmp))
				ft_rotate_up_stack(b);
		else
			while (norm->i++ < (norm->count - norm->tmp))
				ft_rotate_down_stack(b);
	}
	else
	{
		if (norm->stack_a == 'u')
			while (norm->i++ < (norm->best_place_index - norm->tmp))
				ft_rotate_up_stack(a);
		else
			while (norm->i++ < (norm->best_place_index - norm->tmp))
				ft_rotate_down_stack(a);
	}
}

void	ft_different_direction(t_stack *a, t_stack *b, t_norm *norm)
{
	norm->i = 0;
	if (norm->stack_b == 'u')
		while (norm->i++ < norm->count)
			ft_rotate_up_stack(b);
	else
		while (norm->i++ < norm->count)
			ft_rotate_down_stack(b);
	norm->i = 0;
	if (norm->stack_a == 'u')
		while (norm->i++ < norm->best_place_index)
			ft_rotate_up_stack(a);
	else
		while (norm->i++ < norm->best_place_index)
			ft_rotate_down_stack(a);
}

void	ft_push_ab_index(t_stack *a, t_stack *b, int index, int num)
{
	t_norm	norm;

	norm.stack_b = 'u';
	norm.count = index;
	if (index >= ft_stack_size(b) / 2)
	{
		norm.count = ft_stack_size(b) - index;
		norm.stack_b = 'd';
	}
	norm.best_place_index = ft_find_best_place(a, num);
	norm.stack_a = 'u';
	if (norm.best_place_index >= ft_stack_size(a) / 2)
	{
		norm.best_place_index = ft_stack_size(a) - norm.best_place_index;
		norm.stack_a = 'd';
	}
	if (norm.stack_a == norm.stack_b)
		ft_same_direction(a, b, &norm);
	else
		ft_different_direction(a, b, &norm);
	ft_push_from_to(b, a);
}
