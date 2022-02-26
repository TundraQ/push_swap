/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:49:36 by azane             #+#    #+#             */
/*   Updated: 2022/02/26 20:35:04 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_list(t_dblist *lst)
{
	lst->head = 0;
	lst->size = 0;
}

void	ft_push_front_list(t_dblist *lst, int num)
{
	t_node	*new_node;

	new_node = ft_ec_malloc(sizeof(t_node));
	new_node->data = num;
	if (lst->size == 0)
	{
		lst->head = new_node;
		lst->head->next = lst->head;
		lst->head->prev = lst->head;
		lst->size++;
		return ;
	}
	new_node->next = lst->head;
	new_node->prev = lst->head->prev;
	lst->head->prev->next = new_node;
	lst->head->prev = new_node;
	lst->head = new_node;
	lst->size++;
}

void	ft_pop_front_list(t_dblist *lst)
{
	t_node	*to_del;

	if (lst->size == 1)
	{
		free(lst->head);
		lst->head = 0;
		lst->size--;
		return ;
	}
	to_del = lst->head;
	lst->head->prev->next = lst->head->next;
	lst->head->next->prev = lst->head->prev;
	lst->head = lst->head->next;
	free(to_del);
	lst->size--;
}

void	ft_rotate_up_list(t_dblist *lst)
{
	lst->head = lst->head->next;	
}

void	ft_rotate_down_list(t_dblist *lst)
{
	lst->head = lst->head->prev;
}

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
