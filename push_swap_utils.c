/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:10:33 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/05 17:08:49 by souel-bo         ###   ########.fr       */
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
void	rotate_a(t_list **list1)
{
	t_list	*temp;

	if (!list1 || !*list1 || (*list1)->next == NULL)
		return ;
	temp = *list1;
	*list1 = (*list1)->next;
	temp->next = NULL;
	ft_lstadd_back(list1, temp);
	write(1, "ra\n", 3);
}
void	rotate_b(t_list **list2)
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
void	rotate_stacks(t_list **list1, t_list **list2)
{
	rotate_a(&*list1);
	rotate_b(&*list2);
}
void	reverse_rotate_a(t_list **list1)
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
	write(1, "rra\n", 4);
}
void	reverse_rotate_b(t_list **list2)
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
	write(1, "rrb\n", 4);
}
void	reverse_rotate_stacks(t_list **list1, t_list **list2)
{
	reverse_rotate_a(&*list1);
	reverse_rotate_b(&*list2);
}
int	check_if_sorted(t_list **list)
{
	t_list	*head;

	if (!list || !*list)
		return (1);
	head = *list;
	while (head != NULL && head->next != NULL)
	{
		if (*(int *)head->content > *(int *)head->next->content)
			return (0);
		else
			head = head->next;
	}
	return (1);
}
