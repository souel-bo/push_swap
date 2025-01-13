/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:19:10 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/12 17:56:08 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_count(t_list *stack_a)
{
	int	disorder;

	disorder = 0;
	if (ft_lstsize(stack_a) <= 130)
		disorder = 13;
	else if (ft_lstsize(stack_a) <= 230 && ft_lstsize(stack_a) > 130)
		disorder = 21;
	else if (ft_lstsize(stack_a) > 230)
		disorder = 51;
	return (disorder);
}

void	check_move(t_list *tmp, t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*help;
	int		size;

	if (!tmp)
		return ;
	size = ft_lstsize(*stack_b);
	help = (*stack_b);
	i = 0;
	while (help && help->index != tmp->index)
	{
		i++;
		help = help->next;
	}
	while (i <= (size / 2) && i != 0)
	{
		rotate_b(&*stack_b);
		i--;
	}
	while (i > (size / 2) && i < size)
	{
		reverse_rotate_b(&*stack_b);
		i++;
	}
	push_a(&*stack_a, &*stack_b);
}

void	pushing_to_stack_b(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
	{
		if ((*stack_a)->index < ft_lstsize(*stack_b))
		{
			push_b(&*stack_a, &*stack_b);
			rotate_b(&*stack_b);
		}
		else if ((*stack_a)->index < ft_lstsize(*stack_b)
			+ ft_chunk_count(*stack_a))
			push_b(&*stack_a, &*stack_b);
		else
			rotate_a(&*stack_a);
	}
}

void	sort_more_than_six(t_list **stack_a, t_list **stack_b)
{
	t_list	*head2;
	int		*visualise;

	visualise = sorted(*stack_a);
	indexing(*stack_a, visualise);
	pushing_to_stack_b(&*stack_a, &*stack_b);
	while (*stack_b)
	{
		head2 = (*stack_b);
		while (head2 && head2->index != ft_lstsize(*stack_b) - 1)
			head2 = head2->next;
		check_move(head2, &*stack_a, &*stack_b);
	}
	free(visualise);
}
