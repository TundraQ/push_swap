/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 04:17:14 by azane             #+#    #+#             */
/*   Updated: 2022/03/13 04:19:51 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_list(t_dblist *lst)
{
	int	tmp;

	tmp = lst->head->data;
	lst->head->data = lst->head->next->data;
	lst->head->next->data = tmp;
}

void	ft_clear_list(t_dblist *lst)
{
	while (lst->head)
		ft_pop_front_list(lst);
}

void	ft_stiter_next(t_stack_iterator *it)
{
	if (it->node == it->head->prev)
		it->node = 0;
	else
		it->node = it->node->next;
}

int	ft_stiter_value(t_stack_iterator *it)
{
	return (it->node->data);
}

int	ft_stiter_equal(t_stack_iterator *it1, t_stack_iterator *it2)
{
	if (it1->node == it2->node)
		return (1);
	return (0);
}
