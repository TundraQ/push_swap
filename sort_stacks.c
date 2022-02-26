/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:33:10 by azane             #+#    #+#             */
/*   Updated: 2022/02/26 22:36:56 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int		ft_get_min_index(t_stack *stack)
{
	int		min;
	int		index;
	t_node	*node;
	int		i;

	min = stack->lst.head->data;
	node = stack->lst.head->next;
	i = 0;
	index = 0;
	while (node != stack->lst.head)
	{
		if (min > node->data)
		{
			min = node->data;
			index = i;
		}
		node = node->next;
		i++;
	}
	return (index);
}

int		ft_find_best_place(t_stack *stack, int num)
{
	const t_node	*node = stack->lst.head;
	int				i;
	int				index;

	if (num > ft_find_max(stack) || num < ft_find_min(stack))
		return (ft_get_min_index(stack));
	i = 0;
	index = 0; // 4 6 9 1 3     -30 -5 1 3
	while (node->prev->data < num && node->data > num)
	{
		i++;
		
	}
}

int		ft_min_oper_for_index(t_stack *a, t_stack *b, int index)
{
	int	count;

	count = index;
	if (index >= b->lst.size / 2)
		count = b->lst.size - index;
	// TODO
}

void	ft_sort_stack(t_stack *a, t_stack *b)
{
	
}