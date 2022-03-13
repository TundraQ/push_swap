/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 05:23:36 by azane             #+#    #+#             */
/*   Updated: 2022/03/13 06:03:49 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_stack *a)
{
	int					min;
	t_stack_iterator	it;
	t_stack_iterator	end;

	it = ft_stack_begin(a);
	end = ft_stack_end(a);
	min = ft_stiter_value(&it);
	while (!ft_stiter_equal(&it, &end))
	{
		if (ft_stiter_value(&it) < min)
			min = ft_stiter_value(&it);
		ft_stiter_next(&it);
	}
	return (min);
}

int	ft_find_max(t_stack *a)
{
	int					max;
	t_stack_iterator	it;
	t_stack_iterator	end;

	it = ft_stack_begin(a);
	end = ft_stack_end(a);
	max = ft_stiter_value(&it);
	while (!ft_stiter_equal(&it, &end))
	{
		if (ft_stiter_value(&it) > max)
			max = ft_stiter_value(&it);
		ft_stiter_next(&it);
	}
	return (max);
}

int	binarysearch(int value, int *mass, int n)
{
	int	low;
	int	high;
	int	middle;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (value < mass[middle])
			high = middle - 1;
		else if (value > mass[middle])
			low = middle + 1;
		else
			return (middle);
	}
	return (-1);
}

void	ft_starting_position(t_stack *a, t_stack *b)
{
	int	*lis;
	int	size;

	lis = ft_get_best_lis(a, &size);
	while (ft_stack_size(a) != size)
	{
		if (binarysearch(ft_stack_top(a), lis, size) != -1)
			ft_rotate_up_stack(a);
		else
			ft_push_from_to(a, b);
	}
	free(lis);
}
