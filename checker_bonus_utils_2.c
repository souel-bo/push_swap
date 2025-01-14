/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:21:31 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/14 16:32:54 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_bonus(t_list **list)
{
	t_list	*swaper;

	if (!list || !*list || ft_lstsize(*list) < 2)
		return ;
	swaper = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = swaper;
}

void	swap_b_bonus(t_list **list)
{
	t_list	*swaper;

	if (!list || !*list || ft_lstsize(*list) < 2)
		return ;
	swaper = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = swaper;
}

void	swap_stacks_bonus(t_list **list1, t_list **list2)
{
	swap_a(&*list1);
	swap_b(&*list2);
}

void	push_a_bonus(t_list **list1, t_list **list2)
{
	t_list	*temp;

	if (!list2 || !*list2)
		return ;
	temp = *list2;
	(*list2) = (*list2)->next;
	ft_lstadd_front(&*list1, temp);
}

void	push_b_bonus(t_list **list1, t_list **list2)
{
	t_list	*temp;

	if (!list1 || !*list1)
		return ;
	temp = *list1;
	(*list1) = (*list1)->next;
	ft_lstadd_front(&*list2, temp);
}
