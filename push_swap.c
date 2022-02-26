/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:49:11 by azane             #+#    #+#             */
/*   Updated: 2022/02/26 22:24:14 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_stack *a)
{
	int		min;
	t_node	*node;
	
	min = a->lst.head->data;
	node = a->lst.head->next;
	while (node != a->lst.head)
	{
		if (min > node->data)
			min = node->data;
		node = node->next;
	}
	return (min);
}

int	ft_find_max(t_stack *a)
{
	int		max;
	t_node	*node;
	
	max = a->lst.head->data;
	node = a->lst.head->next;
	while (node != a->lst.head)
	{
		if (max < node->data)
			max = node->data;
		node = node->next;
	}
	return (max);
}

void	ft_starting_position(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	
	min = ft_find_min(a);
	max = ft_find_max(a);
	while (a->lst.size > 2)
	{
		if (a->lst.head->data == min || a->lst.head->data == max)
			ft_rotate_up_stack(a);
		else
		{
			ft_push_stack(b, a->lst.head->data);
			ft_pop_stack(a);
		}
	}
}
