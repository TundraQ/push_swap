/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:33:10 by azane             #+#    #+#             */
/*   Updated: 2022/03/09 18:53:27 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int		ft_get_min_index(t_stack *stack)
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

// it: 0 - it 1 - prev 2 - end
int		ft_find_best_place(t_stack *stack, int num)
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

static int ft_max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

static int ft_min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int		ft_min_oper_for_elem(t_stack *a, t_stack *b, int index, int num) // take into account rr
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
		//count += ft_stack_size(a) - best_place_index;
		best_place_index = ft_stack_size(a) - best_place_index;
		stack_b = 'd';
	}
	if (stack_a == stack_b)
		return ft_max(count, best_place_index);
	return (count + best_place_index);
}

void	ft_push_ab_index(t_stack *a, t_stack *b, int index, int num) // take into account rr
{
	int		count;
	int		best_place_index;
	char	stack_a;
	char	stack_b;

	stack_b = 'u';
	count = index;
	if (index >= ft_stack_size(b) / 2)
	{
		count = ft_stack_size(b) - index;
		stack_b = 'd';	
	}
	best_place_index = ft_find_best_place(a, num);
	stack_a = 'u';
	if (best_place_index >= ft_stack_size(a) / 2)
	{
		//count += ft_stack_size(a) - best_place_index;
		best_place_index = ft_stack_size(a) - best_place_index;
		stack_a = 'd';
	}
	if (stack_a == stack_b)
	{
		int tmp = ft_min(count, best_place_index);
		for (int i = 0; i < tmp; ++i)
			ft_rotate_stacks(a, b, stack_a);
		if (count > tmp)
		{
			if (stack_a == 'u')
			{
				for (int i = 0; i < count - tmp; ++i)
					ft_rotate_up_stack(b);
			}
			else
			{
				for (int i = 0; i < count - tmp; ++i)
					ft_rotate_down_stack(b);
			}
		}
		else
		{
			if (stack_a == 'u')
			{
				for (int i = 0; i < best_place_index - tmp; ++i)
					ft_rotate_up_stack(a);
			}
			else
			{
				for (int i = 0; i < best_place_index - tmp; ++i)
					ft_rotate_down_stack(a);
			}
		}
	}		
	else
	{
		if (stack_b == 'u')
		{
			for (int i = 0; i < count; ++i)
				ft_rotate_up_stack(b);
		}
		else
		{
			for (int i = 0; i < count; ++i)
				ft_rotate_down_stack(b);
		}
		if (stack_a == 'u')
		{
			for (int i = 0; i < best_place_index; ++i)
				ft_rotate_up_stack(a);
		}
		else
		{
			for (int i = 0; i < best_place_index; ++i)
				ft_rotate_down_stack(a);
		}
	}
	ft_push_from_to(b, a);
}

// void	ft_push_ab_index(t_stack *a, t_stack *b, int index, int num) // take into account rr
// {
// 	int		count;
// 	int		best_place_index;
// 	char	stack_a;
// 	char	stack_b;

// 	count = index;
// 	if (index >= ft_stack_size(b) / 2)
// 	{
// 		count = ft_stack_size(b) - index;
// 		while (count--)
// 			ft_rotate_down_stack(b);
// 	}
// 	else
// 	{
// 		while (count--)
// 			ft_rotate_up_stack(b);
// 	}
// 	best_place_index = ft_find_best_place(a, num);
// 	if (best_place_index >= ft_stack_size(a) / 2)
// 	{
// 		best_place_index = ft_stack_size(a) - best_place_index;
// 		while (best_place_index--)
// 			ft_rotate_down_stack(a);
// 	}
// 	else
// 	{
// 		while (best_place_index--)
// 			ft_rotate_up_stack(a);
// 	}
// 	ft_push_from_to(b, a);
// }

void	ft_end(t_stack *a)
{
	int	index;

	index = ft_get_min_index(a);
	if (index >= ft_stack_size(a) / 2)
	{
		index = ft_stack_size(a) - index;
		while (index--)
			ft_rotate_down_stack(a);
	}
	else
	{
		while (index--)
			ft_rotate_up_stack(a);
	}
}

void	ft_sort_stack(t_stack *a, t_stack *b)
{
	int					min_oper_for_best;
	int					index_of_best;
	t_stack_iterator	it;
	t_stack_iterator	end;
	int					index;
	int					num;

	ft_starting_position(a, b);
	while (ft_stack_size(b) > 0)
	{
		it = ft_stack_begin(b);
		end = ft_stack_end(b);
		min_oper_for_best = INT_MAX;
		index = 0;
		while (!ft_stiter_equal(&it, &end))
		{
			if (ft_min_oper_for_elem(a, b, index, ft_stiter_value(&it)) < min_oper_for_best) // VERY SLOWLY (fix me)
			{
				min_oper_for_best = ft_min_oper_for_elem(a, b, index, ft_stiter_value(&it));
				index_of_best = index;
				num = ft_stiter_value(&it);
			}
			ft_stiter_next(&it);
			index++;
		}
		ft_push_ab_index(a, b, index_of_best, num);
	}
	ft_end(a);
}
