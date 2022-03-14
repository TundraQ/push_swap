/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:26:01 by azane             #+#    #+#             */
/*   Updated: 2022/03/14 19:45:15 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

void	ft_rotate_up_stack_bonus(t_stack *stack);
void	ft_rotate_down_stack_bonus(t_stack *stack);
void	ft_swap_stack_bonus(t_stack *stack);
void	ft_rotate_stacks_bonus(t_stack *a, t_stack *b, char side);
void	ft_push_from_to_bonus(t_stack *from, t_stack *to);
void	ft_print_result(char *res, t_stack *a, t_stack *b);
void	ft_check_stack(t_stack *a, t_stack *b);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_checker(t_stack *a, t_stack *b);
void	ft_swap_both_stacks(t_stack *a, t_stack *b);

#endif