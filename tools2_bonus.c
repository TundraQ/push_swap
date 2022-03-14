/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:30:00 by azane             #+#    #+#             */
/*   Updated: 2022/03/14 19:44:07 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

void	ft_swap_both_stacks(t_stack *a, t_stack *b)
{
	ft_swap_stack_bonus(a);
	ft_swap_stack_bonus(b);
}

void	ft_print_result(char *res, t_stack *a, t_stack *b)
{
	ft_printf(res);
	ft_clear_stack(a);
	ft_clear_stack(b);
	exit (0);
}

void	ft_check_stack(t_stack *a, t_stack *b)
{
	t_stack_iterator	it;
	t_stack_iterator	end;
	t_stack_iterator	next;

	if (ft_stack_size(b))
		ft_print_result("KO\n", a, b);
	it = ft_stack_begin(a);
	end = ft_stack_end(a);
	next = ft_stack_begin(a);
	ft_stiter_next(&next);
	while (ft_stiter_equal(&next, &end) == 0)
	{
		if (ft_stiter_value(&it) > ft_stiter_value(&next))
			ft_print_result("KO\n", a, b);
		ft_stiter_next(&it);
		ft_stiter_next(&next);
	}
	ft_print_result("OK\n", a, b);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s1[i] != '\n' && s2[i] != '\n')
		i++;
	if (s1[i] == '\n' && s2[i] == '\0')
		return (0);
	if (s1[i] == '\0' && s2[i] == '\n')
		return (0);
	return (s1[i] - s2[i]);
}
