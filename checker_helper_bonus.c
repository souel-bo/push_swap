/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:00:16 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/14 16:12:30 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(long *number, char **split, t_list **list)
{
	if (!number)
	{
		free_split(split);
		ft_lstclear(&*list, free);
		return ;
	}
}

char	**parse_input(char *argument, t_list **list)
{
	char	**split;

	split = ft_split(argument, ' ');
	if (!split || split[0] == NULL || split[0][0] == '\0')
		ft_handle_2(split, list);
	return (split);
}

void	process_number(char *str, t_list **list, char **split)
{
	long	*number;
	t_list	*element;

	number = malloc(sizeof(long));
	if (!number)
		ft_handle(split, list, NULL);
	ft_check(number, split, list);
	*number = ft_atoi(str);
	if (*number == 21474836471)
	{
		ft_error("Error\n");
		ft_handle(split, list, number);
		list = NULL;
		exit(EXIT_FAILURE);
	}
	element = ft_lstnew(number);
	if (!element)
		ft_handle(split, list, number);
	ft_lstadd_back(list, element);
}

t_list	*create_list(char *argument, t_list **list)
{
	char	**split;
	int		i;

	split = parse_input(argument, list);
	i = 0;
	while (split[i])
	{
		process_number(split[i], list, split);
		i++;
	}
	free_split(split);
	return (*list);
}
