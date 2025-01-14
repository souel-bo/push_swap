/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:23:58 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/14 16:31:53 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b_bonus(t_list **list2)
{
	t_list	*temp;

	if (!list2 || !*list2 || (*list2)->next == NULL)
		return ;
	temp = *list2;
	*list2 = (*list2)->next;
	temp->next = NULL;
	ft_lstadd_back(list2, temp);
	write(1, "rb\n", 3);
}

void	rotate_stacks_bonus(t_list **list1, t_list **list2)
{
	rotate_a(&*list1);
	rotate_b(&*list2);
}

void	reverse_rotate_a_bonus(t_list **list1)
{
	t_list	*temp;
	t_list	*before_last;

	if (!list1 || !*list1 || (*list1)->next == NULL)
		return ;
	temp = ft_lstlast(*list1);
	before_last = *list1;
	while (before_last->next != temp)
		before_last = before_last->next;
	before_last->next = NULL;
	ft_lstadd_front(&*list1, temp);
}

void	reverse_rotate_b_bonus(t_list **list2)
{
	t_list	*temp;
	t_list	*before_last;

	if (!list2 || !*list2 || (*list2)->next == NULL)
		return ;
	temp = ft_lstlast(*list2);
	before_last = *list2;
	while (before_last->next != temp)
		before_last = before_last->next;
	before_last->next = NULL;
	ft_lstadd_front(&*list2, temp);
}

void	reverse_rotate_stacks_bonus(t_list **list1, t_list **list2)
{
	reverse_rotate_a(&*list1);
	reverse_rotate_b(&*list2);
}
