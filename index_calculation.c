/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 06:05:07 by azane             #+#    #+#             */
/*   Updated: 2022/03/13 06:55:41 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_find_best_place(t_stack *stack, int num)
{
	int					i;
	t_stack_iterator	it[3];

	if (num > ft_find_max(stack) || num < ft_find_min(stack))
		return (ft_get_min_index(stack));
	i = 1;
	it[0] = ft_stack_begin(stack);
	it[1] = ft_stack_begin(stack);
	it[2] = ft_stack_end(stack);
	ft_stiter_next(&it[0]);
	while (!ft_stiter_equal(&it[0], &it[2]))
	{
		if (num > ft_stiter_value(&it[1]) && num < ft_stiter_value(&it[0]))
			return (i);
		i++;
		ft_stiter_next(&it[0]);
		ft_stiter_next(&it[1]);
	}
	it[0] = ft_stack_begin(stack);
	if (num > ft_stiter_value(&it[1]) && num < ft_stiter_value(&it[0]))
		return (0);
	return (-1);
}

int	ft_get_min_index(t_stack *stack)
{
	int					min;
	int					index;
	t_stack_iterator	it[2];
	int					i;

	it[0] = ft_stack_begin(stack);
	it[1] = ft_stack_end(stack);
	min = ft_stack_top(stack);
	i = 0;
	index = 0;
	while (!ft_stiter_equal(&it[0], &it[1]))
	{
		if (min > ft_stiter_value(&it[0]))
		{
			min = ft_stiter_value(&it[0]);
			index = i;
		}
		ft_stiter_next(&it[0]);
		i++;
	}
	return (index);
}

int	ft_min_oper_for_elem(t_stack *a, t_stack *b, int index, int num)
{
	int		count;
	int		best_place_index;
	char	stack_a;
	char	stack_b;

	stack_a = 'u';
	count = index;
	if (index >= ft_stack_size(b) / 2)
	{
		count = ft_stack_size(b) - index;
		stack_a = 'd';
	}
	best_place_index = ft_find_best_place(a, num);
	stack_b = 'u';
	if (best_place_index >= ft_stack_size(a) / 2)
	{
		best_place_index = ft_stack_size(a) - best_place_index;
		stack_b = 'd';
	}
	if (stack_a == stack_b)
		return (ft_max(count, best_place_index));
	return (count + best_place_index);
}
