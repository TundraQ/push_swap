/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_little_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 04:51:38 by azane             #+#    #+#             */
/*   Updated: 2022/03/13 05:05:14 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_top_less(t_stack *main, t_stack *_help, int count)
{
	int	count2;

	if (count <= 1)
		return ;
	if (count == 2)
	{
		if (main->lst.head->data > main->lst.head->next->data)
			ft_swap_stack(main);
		return ;
	}
	if (count == ft_stack_size(main))
	{
		if (ft_optimize_top_less(main) != -1)
			return ;
	}
	if (count == 3)
	{
		if (ft_sort_3_top_less(main, _help))
			return ;
	}
	count2 = ft_stack_push_mid_less(main, _help, count);
	ft_sort_top_less(main, _help, count - count2);
	ft_sort_top_bigger(_help, main, count2);
	ft_stack_push_nelem(_help, main, count2);
}

static int	ft_stack_push_mid_less_util(t_stack *from, t_stack *to,
	int count, int *size)
{
	int	i;
	int	median;
	int	rotate_count;

	median = ft_lst_get_median(&from->lst, count);
	i = 0;
	rotate_count = 0;
	*size = 0;
	while (i++ < count)
	{
		if (ft_stack_top(from) < median)
		{
			ft_push_from_to(from, to);
			(*size)++;
			if ((*size) == (count / 2))
				break ;
		}
		else
		{
			ft_rotate_up_stack(from);
			rotate_count++;
		}
	}
	return (rotate_count);
}

int	ft_stack_push_mid_less(t_stack *from, t_stack *to, int count)
{
	int	size;
	int	i;
	int	rotate_count;
	int	flag;

	flag = 0;
	if (ft_stack_size(from) == count)
		flag = 1;
	rotate_count = ft_stack_push_mid_less_util(from, to, count, &size);
	if (flag)
		return (count / 2);
	i = 0;
	while (i++ < rotate_count)
		ft_rotate_down_stack(from);
	return (count / 2);
}

static int	ft_stack_push_mid_bigger_util(t_stack *from, t_stack *to,
	int count, int *size)
{
	int	i;
	int	median;
	int	rotate_count;

	median = ft_lst_get_median(&from->lst, count);
	i = 0;
	rotate_count = 0;
	*size = 0;
	while (i++ < count)
	{
		if (ft_stack_top(from) >= median)
		{
			ft_push_from_to(from, to);
			(*size)++;
			if ((*size) == ((count + 1) / 2))
				break ;
		}
		else
		{
			ft_rotate_up_stack(from);
			rotate_count++;
		}
	}
	return (rotate_count);
}

int	ft_stack_push_mid_bigger(t_stack *from, t_stack *to, int count)
{
	int	size;
	int	i;
	int	rotate_count;
	int	flag;

	flag = 0;
	if (ft_stack_size(from) == count)
		flag = 1;
	rotate_count = ft_stack_push_mid_bigger_util(from, to, count, &size);
	if (flag)
		return (size);
	i = 0;
	while (i++ < rotate_count)
		ft_rotate_down_stack(from);
	return ((count + 1) / 2);
}
