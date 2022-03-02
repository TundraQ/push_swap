/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_iterator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:43:46 by azane             #+#    #+#             */
/*   Updated: 2022/03/02 16:48:58 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_stiter_next(t_stack_iterator *it)
{
	if (it->node == it->head->prev)
		it->node = 0;
	else
		it->node = it->node->next;
}

int					ft_stiter_value(t_stack_iterator *it)
{
	return (it->node->data);
}

int					ft_stiter_equal(t_stack_iterator *it1, t_stack_iterator *it2)
{
	if (it1->node == it2->node)
		return (1);
	return (0);
}

t_stack_iterator	ft_stack_begin(t_stack *stack)
{
	t_stack_iterator	tmp;

	tmp.head = stack->lst.head;
	tmp.node = stack->lst.head;
	return (tmp);
}

t_stack_iterator	ft_stack_end(t_stack *stack)
{
	t_stack_iterator	tmp;

	tmp.head = stack->lst.head;
	tmp.node = 0;
	return (tmp);
}