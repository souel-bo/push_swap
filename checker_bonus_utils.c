/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:23:58 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/14 11:24:58 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_bonus(t_list **list1)
{
	t_list	*temp;

	if (!list1 || !*list1 || (*list1)->next == NULL)
		return ;
	temp = *list1;
	*list1 = (*list1)->next;
	temp->next = NULL;
	ft_lstadd_back(list1, temp);
	//write(1, "ra\n", 3);
}