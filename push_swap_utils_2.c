/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 07:14:55 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/13 07:15:09 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **list)
{
	t_list	*swaper;

	if (!list || !*list || ft_lstsize(*list) < 2)
		return ;
	swaper = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = swaper;
	write(1, "sa\n", 3);
}

void	swap_b(t_list **list)
{
	t_list	*swaper;

	if (!list || !*list || ft_lstsize(*list) < 2)
		return ;
	swaper = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = swaper;
	write(1, "sb\n", 3);
}

void	swap_stacks(t_list **list1, t_list **list2)
{
	swap_a(&*list1);
	swap_b(&*list2);
}

void	push_a(t_list **list1, t_list **list2)
{
	t_list	*temp;

	if (!list2 || !*list2)
		return ;
	temp = *list2;
	(*list2) = (*list2)->next;
	ft_lstadd_front(&*list1, temp);
	write(1, "pa\n", 3);
}

void	push_b(t_list **list1, t_list **list2)
{
	t_list	*temp;

	if (!list1 || !*list1)
		return ;
	temp = *list1;
	(*list1) = (*list1)->next;
	ft_lstadd_front(&*list2, temp);
	write(1, "pb\n", 3);
}
