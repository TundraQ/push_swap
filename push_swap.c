/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:49:11 by azane             #+#    #+#             */
/*   Updated: 2022/03/09 00:05:43 by azane            ###   ########.fr       */
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
