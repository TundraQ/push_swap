/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:28:46 by azane             #+#    #+#             */
/*   Updated: 2022/03/09 18:52:17 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
# include <stdio.h>

void	ft_print_stack(t_stack *stack)
{
	const t_node	*node = stack->lst.head;

	if (!stack->lst.head)
		return ;
	while (node != stack->lst.head->prev)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
	printf("%d\n", node->data);
}

int main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	(void) argc;
	(void) argv;
	ft_init_stack(&a);
	ft_init_stack(&b);
	a.type = 'a';
	b.type = 'b';
	for (int i = argc - 1; i > 0; i--)
		ft_push_stack(&a, ft_atoi(argv[i]));
	ft_sort_stack(&a, &b);
}
