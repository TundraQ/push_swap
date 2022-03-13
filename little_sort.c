/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 04:42:34 by azane             #+#    #+#             */
/*   Updated: 2022/03/13 05:13:06 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_3elem(t_stack *stack)
{
	const t_node	*h = stack->lst.head;

	if (ft_stack_size(stack) > 3)
		return (-1);
	if (h->data < h->next->data && h->next->data > h->next->next->data
		&& h->prev->data > h->data)
		return (ft_printf("sa\nra\n"));
	if (h->data > h->next->data && h->next->data < h->next->next->data
		&& h->prev->data > h->data)
		return (ft_printf("sa\n"));
	if (h->data < h->next->data && h->next->data > h->next->next->data
		&& h->prev->data < h->data)
		return (ft_printf("rra\n"));
	if (h->data > h->next->data && h->next->data < h->next->next->data
		&& h->prev->data < h->data)
		return (ft_printf("ra\n"));
	if (h->data > h->next->data && h->next->data > h->next->next->data
		&& h->prev->data < h->data)
		return (ft_printf("ra\nsa\n"));
	return (-1);
}

int	ft_sort_5elem(t_stack *stack, t_stack *_help)
{
	if (ft_stack_size(stack) <= 7)
	{
		ft_sort_top_less(stack, _help, ft_stack_size(stack));
		return (1);
	}
	return (-1);
}

int	ft_optimize_top_bigger(t_stack *stack)
{
	const t_node	*node = stack->lst.head;
	int				number;
	int				i;

	number = -1;
	i = 0;
	while (i < stack->lst.size)
	{
		if (node->data < node->next->data)
		{
			if (number != -1)
				return (-1);
			number = i;
		}
		node = node->next;
		i++;
	}
	i = -1;
	if (((number + 1) % stack->lst.size) <= stack->lst.size / 2)
		while (++i < ((number + 1) % stack->lst.size))
			ft_rotate_up_stack(stack);
	else
		while (++i < stack->lst.size - ((number + 1) % stack->lst.size))
			ft_rotate_down_stack(stack);
	return (0);
}

void	ft_sort_top_bigger(t_stack *main, t_stack *_help, int count)
{
	int	count2;

	if (count <= 1)
		return ;
	if (count == 2)
	{
		if (main->lst.head->data < main->lst.head->next->data)
			ft_swap_stack(main);
		return ;
	}
	if (count == main->lst.size)
	{
		if (ft_optimize_top_bigger(main) != -1)
			return ;
	}
	if (count == 3)
	{
		if (ft_sort_3_top_bigger(main, _help))
			return ;
	}
	count2 = ft_stack_push_mid_bigger(main, _help, count);
	ft_sort_top_bigger(main, _help, count - count2);
	ft_sort_top_less(_help, main, count2);
	ft_stack_push_nelem(_help, main, count2);
}

int	ft_optimize_top_less(t_stack *stack)
{
	const t_node	*node = stack->lst.head;
	int				number;
	int				i;

	number = -1;
	i = -1;
	while (++i < ft_stack_size(stack))
	{
		if (node->data > node->next->data)
		{
			if (number != -1)
				return (-1);
			number = i;
		}
		node = node->next;
	}
	i = 0;
	if (((number + 1) % ft_stack_size(stack)) <= ft_stack_size(stack) / 2)
		while (i++ < ((number + 1) % ft_stack_size(stack)))
			ft_rotate_up_stack(stack);
	else
		while (i++ < ft_stack_size(stack)
			- ((number + 1) % ft_stack_size(stack)))
			ft_rotate_down_stack(stack);
	return (0);
}
