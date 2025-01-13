/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:40:28 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/13 15:13:44 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_handle(char **split, t_list **list, long *number)
{
	free_split(split);
	ft_lstclear(&*list, free);
	free(number);
}

void	ft_handle_2(char **split, t_list **list)
{
	free_split(split);
	ft_error("Error\n");
	ft_lstclear(list, free);
	exit(EXIT_FAILURE);
}

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
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
