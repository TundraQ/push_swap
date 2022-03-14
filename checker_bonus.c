/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:53:27 by azane             #+#    #+#             */
/*   Updated: 2022/03/14 19:51:45 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

void	ft_switch_case(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_swap_stack_bonus(a);
	else if (ft_strcmp(line, "sb") == 0)
		ft_swap_stack_bonus(b);
	else if (ft_strcmp(line, "ss") == 0)
		ft_swap_both_stacks(a, b);
	else if (ft_strcmp(line, "pa") == 0)
		ft_push_from_to_bonus(b, a);
	else if (ft_strcmp(line, "pb") == 0)
		ft_push_from_to_bonus(a, b);
	else if (ft_strcmp(line, "ra") == 0)
		ft_rotate_up_stack_bonus(a);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rotate_up_stack_bonus(b);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rotate_stacks_bonus(a, b, 'u');
	else if (ft_strcmp(line, "rra") == 0)
		ft_rotate_down_stack_bonus(a);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rotate_down_stack_bonus(b);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rotate_stacks_bonus(a, b, 'd');
	else if (line)
		ft_print_result("Error\n", a, b);
}

void	ft_checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ft_switch_case(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	ft_check_stack(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		j;

	if (argc < 2)
		return (0);
	ft_init_stack(&a, 0);
	ft_init_stack(&b, 0);
	i = 1;
	while (i <= argc - 2)
	{
		j = i + 1;
		while (j <= argc - 1)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j++]))
				ft_fatal("");
		i++;
	}
	i = argc - 1;
	while (i > 0)
		ft_push_stack(&a, ft_check_arg(argv[i--]));
	ft_checker(&a, &b);
	return (0);
}
