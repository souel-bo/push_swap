/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:19:10 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/11 10:45:49 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *sorted(t_list *list)
{
    int i;
    int swap;
    int *tab;
    int size = ft_lstsize(list);
    int j;

    tab = (int *)malloc(sizeof(int) * (size));
    if (!tab)
        return (0);
    i = 0;
    while (list != NULL)
    {
        tab[i] = *(int *)list->content;
        list = list->next;
        i++;
    }
    i = 0;
    while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i++;
	}
    return (tab);
}
void indexing(t_list *list, int *sorted_array)
{
  int size = ft_lstsize(list);
  int i;
  t_list *current = list;

  while (current != NULL)
  {
    i = 0;
    while (i < size)
    {
      if (*(int *)current->content == sorted_array[i])
      {
        current->index = i;
        break;
      }
      i++;
    }
    current = current->next;
  }
}

int ft_order_count(t_list *stack_a)
{
  int calculation_disorder;
  if (ft_lstsize(stack_a) <= 130)
    calculation_disorder = 13;
  else if (ft_lstsize(stack_a) > 130 && ft_lstsize(stack_a) <= 230)
    calculation_disorder = 21;
  else if (ft_lstsize(stack_a) > 230)
    calculation_disorder = 51;
  return (calculation_disorder);
}

void check_move(t_list *tmp, t_list **stack_a, t_list **stack_b)
{
	int i;
	t_list *help;
	int size;

	if(!tmp)
		return;
	size = ft_lstsize(*stack_b);
	help = (*stack_b);
	i = 0;
	while(help && help->index != tmp->index)
	{
		i++;
		help =help->next;
	}
	while(i <= (size / 2) && i != 0)
	{
		rotate_b(&*stack_b);
		i--;
	}
	while(i > (size / 2) && i < size)
	{
		reverse_rotate_b(&*stack_b);
		i++;
	}
	push_a(&*stack_a, &*stack_b);
}

void sort_more_than_six(t_list **stack_a, t_list **stack_b)
{
  t_list *head2;
  int *visualise = sorted(*stack_a);
  indexing(*stack_a, visualise);
  while (*stack_a)
  {
    if ((*stack_a)->index < ft_lstsize(*stack_b))
    {
      push_b(&*stack_a, &*stack_b);
      rotate_b(&*stack_b);
    }
    else if ((*stack_a)->index < ft_lstsize(*stack_b) + ft_order_count(*stack_a))
      push_b(&*stack_a, &*stack_b);
    else
        rotate_a(&*stack_a);
  }
  while (*stack_b)
  {
    head2 = (*stack_b);
    while (head2 && head2->index != ft_lstsize(*stack_b) - 1)
      head2 = head2->next;
    check_move(head2 ,&*stack_a, &*stack_b);
  }
  free(visualise);
}

