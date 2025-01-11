/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:06:13 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/11 10:01:05 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error(char *msg)
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

t_list *create_list(char *argument, t_list **list)
{
	int		*number;
	char	**split;
	int		i;
	t_list	*element;

	i = 0;
	split = ft_split(argument, ' ');
	if (!split || split[0] == (NULL) || split[0][0] == '\0')
	{
		free_split(split);
		ft_error("Error\n");
		exit(EXIT_FAILURE);
	}
	while (split[i])
	{
		number = malloc(sizeof(int));
		if (!number)
		{
			free_split(split);
			ft_lstclear(&*list, free);
			return (NULL);
		}
		if (split[i][0] != '0' && (ft_atoi(split[i])) == 0)
		{
			ft_error("Error\n");
			free_split(split);
			ft_lstclear(&*list, free);
			free(number);
			list = NULL;
			exit(EXIT_FAILURE);
		}
		*number = ft_atoi(split[i]);
		element = ft_lstnew(number);
		if (!element)
		{
			free_split(split);
			ft_lstclear(&*list, free);
			free(number);
			return (NULL);
		}
		ft_lstadd_back(&*list, element);
		i++;
	}
	free_split(split);
	return (*list);
}

void check_list(t_list *list)
{
	t_list *start = list;
	t_list *check;
	while (start->next != NULL)
	{
		check = start->next;
		while (check != NULL)
		{
			if (*(int *)(start->content) == *(int *)(check->content))
			{
				printf("duplicate");
				ft_error("Error\n");
				ft_lstclear(&list, free);
				exit(EXIT_FAILURE);
			}
			check = check->next;
		}
		start = start->next;
	}
}
void print(t_list *list)
{
	t_list *start;
	
	start = list;
	while (start != NULL)
	{
		printf("%d\n", *(int *)start->content);
		start = start->next;
	}
}

int main(int argc, char **argv)
{
    int 	i;
	t_list	*list;
	t_list	*list_2;
	int		number;

	if (argc < 2)
		return (1);
	i = 1;
	list = NULL;
	list_2 = NULL;
    while (i < argc)
    {
		list = create_list(argv[i], &list);
		i++;
    }
	if (ft_lstsize(list) < 2)
		return (1);
	check_list(list);
	if (check_if_sorted(&list) == 1)
	{
		ft_lstclear(&list, free);
		exit(EXIT_FAILURE);
	}
	check_size(&list, &list_2);
	print(list);
	ft_lstclear(&list, free);
	ft_lstclear(&list_2, free);
}
