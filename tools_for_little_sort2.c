/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_little_sort2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 05:08:21 by azane             #+#    #+#             */
/*   Updated: 2022/03/13 05:09:53 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push_nelem(t_stack *from, t_stack *to, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_push_from_to(from, to);
		i++;
	}
}

int	ft_sort_33_top_less(t_stack *main, t_stack *_help)
{
	const t_node	*node = main->lst.head;

	(void) _help;
	if (node->data > node->next->data)
	{
		if (node->next->data > node->next->next->data)
		{
			ft_rotate_up_stack(main);
			ft_swap_stack(main);
			return (1);
		}
		else
		{
			ft_swap_stack(main);
			return (1);
		}
	}
	else if (node->next->data > node->next->next->data)
	{
		ft_rotate_down_stack(main);
		ft_swap_stack(main);
		return (1);
	}
	return (0);
}

int	ft_sort_3_top_less(t_stack *main, t_stack *_help)
{
	const t_node	*node = main->lst.head;

	if (main->lst.size == 3)
		return (ft_sort_33_top_less(main, _help));
	else
	{
		if (node->data > node->next->data)
		{
			if (node->next->data < node->next->next->data)
			{
				ft_swap_stack(main);
				return (1);
			}
		}
	}
	return (0);
}

int	ft_sort_33_top_bigger(t_stack *main, t_stack *_help)
{
	const t_node	*node = main->lst.head;

	(void) _help;
	if (node->data < node->next->data)
	{
		if (node->next->data < node->next->next->data)
		{
			ft_rotate_up_stack(main);
			ft_swap_stack(main);
			return (1);
		}
		else
		{
			ft_swap_stack(main);
			return (1);
		}
	}
	else if (node->next->data < node->next->next->data)
	{
		ft_rotate_down_stack(main);
		ft_swap_stack(main);
		return (1);
	}
	return (0);
}

int	ft_sort_3_top_bigger(t_stack *main, t_stack *_help)
{
	const t_node	*node = main->lst.head;

	if (main->lst.size == 3)
		return (ft_sort_33_top_bigger(main, _help));
	else
	{
		if (node->data < node->next->data)
		{
			if (node->next->data > node->next->next->data)
			{
				ft_swap_stack(main);
				return (1);
			}
		}
	}
	return (0);
}
