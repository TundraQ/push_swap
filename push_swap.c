/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 03:02:17 by azane             #+#    #+#             */
/*   Updated: 2022/03/14 20:08:55 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_norm
{
	int					min_oper_for_best;
	int					index_of_best;
	t_stack_iterator	it;
	t_stack_iterator	end;
	int					index;
	int					num;
}	t_norm;

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

void	ft_sort_step(t_stack *a, t_stack *b, t_norm *norm)
{
	norm->it = ft_stack_begin(b);
	norm->end = ft_stack_end(b);
	norm->min_oper_for_best = INT_MAX;
	norm->index = 0;
	while (!ft_stiter_equal(&norm->it, &norm->end))
	{
		if (ft_min_oper_for_elem(a, b, norm->index,
				ft_stiter_value(&norm->it)) < norm->min_oper_for_best)
		{
			norm->min_oper_for_best = ft_min_oper_for_elem(a, b, norm->index,
					ft_stiter_value(&norm->it));
			norm->index_of_best = norm->index;
			norm->num = ft_stiter_value(&norm->it);
		}
		ft_stiter_next(&norm->it);
		norm->index++;
	}
	ft_push_ab_index(a, b, norm->index_of_best, norm->num);
}

void	ft_sort_stack(t_stack *a, t_stack *b)
{
	t_norm	norm;

	if (ft_sort_3elem(a) != -1)
		return ;
	if (ft_optimize_top_less(a) != -1)
		return ;
	if (ft_sort_5elem(a, b) != -1)
		return ;
	ft_starting_position(a, b);
	while (ft_stack_size(b) > 0)
		ft_sort_step(a, b, &norm);
	ft_end(a);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		j;

	if (argc == 1)
		return (0);
	ft_init_stack(&a, 'a');
	ft_init_stack(&b, 'b');
	i = 1;
	while (i <= argc - 2)
	{
		j = i + 1;
		while (j <= argc - 1)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j++]))
				ft_fatal("");
		i++;
	}
	i = argc - 1;
	while (i > 0)
		ft_push_stack(&a, ft_check_arg(argv[i--]));
	ft_sort_stack(&a, &b);
	ft_clear_stack(&a);
	ft_clear_stack(&b);
	return (0);
}
