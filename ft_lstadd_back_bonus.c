/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:46:49 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/14 16:32:02 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

void	rotate_a_bonus(t_list **list1)
{
	t_list	*temp;

	if (!list1 || !*list1 || (*list1)->next == NULL)
		return ;
	temp = *list1;
	*list1 = (*list1)->next;
	temp->next = NULL;
	ft_lstadd_back(list1, temp);
}
