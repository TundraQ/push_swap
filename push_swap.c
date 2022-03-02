/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:49:11 by azane             #+#    #+#             */
/*   Updated: 2022/03/02 17:00:56 by azane            ###   ########.fr       */
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

void	ft_starting_position(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = ft_find_min(a);
	max = ft_find_max(a);
	while (ft_stack_size(a) > 2)
	{
		if (ft_stack_top(a) == min || ft_stack_top(a) == max)
			ft_rotate_up_stack(a);
		else
			ft_push_from_to(a, b);
	}
}
