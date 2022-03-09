/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:00:27 by azane             #+#    #+#             */
/*   Updated: 2022/03/09 00:33:21 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_lis(t_stack *stack, int *size)
{
	int					*p;
	int					*d;
	int					*values;
	int					*lis;
	t_stack_iterator	it;
	t_stack_iterator	end;
	int					i;

	values = malloc(ft_stack_size(stack) * sizeof(int));
	d = malloc(ft_stack_size(stack) * sizeof(int));
	p = malloc(ft_stack_size(stack) * sizeof(int));
	lis = malloc(ft_stack_size(stack) * sizeof(int));
	it = ft_stack_begin(stack);
	end = ft_stack_end(stack);
	i = 0;
	while (!ft_stiter_equal(&it, &end))
	{
		values[i++] = ft_stiter_value(&it);
		ft_stiter_next(&it);
	}
	i = 0;
	while (i < ft_stack_size(stack))
	{
		d[i] = 1;
		p[i] = -1;
		for (int j=0; j<i; ++j)
			if (values[j] < values[i])
				if (1 + d[j] > d[i]) {
					d[i] = 1 + d[j];
					p[i] = j;
				}
		i++;
	}
	int pos = i - 1;
	i = 0;
	while (pos != -1)
	{
		lis[i++] = values[pos];
		pos = p[pos];
	}
	for (int j = 0; j < i/2; j++)
	{
		int tmp = lis[j];
		lis[j] = lis[i - j - 1];
		lis[i - j - 1] = tmp;
	}
	*size = i;
	free(values);
	free(d);
	free(p);
	return lis;
}

int binarysearch(int value, int *mass, int n)
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
            return middle;
    }
    return -1;
}

//#include <stdio.h>
void	ft_starting_position(t_stack *a, t_stack *b)
{
	int	*lis;
	int	size;

	lis = ft_get_lis(a, &size);
	while (ft_stack_size(a) != size)
	{
		if (binarysearch(ft_stack_top(a), lis, size) != -1)
			ft_rotate_up_stack(a);
		else
			ft_push_from_to(a, b);
	}
	free(lis);
	//fprintf(stderr, "!%d!\n", size);
}

// void	ft_starting_position(t_stack *a, t_stack *b)
// {
// 	int	min;
// 	int	max;

// 	//lis = ft_get_lis(a);
// 	min = ft_find_min(a);
// 	max = ft_find_max(a);
// 	while (ft_stack_size(a) > 2)
// 	{
// 		if (ft_stack_top(a) == min || ft_stack_top(a) == max)
// 			ft_rotate_up_stack(a);
// 		else
// 			ft_push_from_to(a, b);
// 	}
// }
