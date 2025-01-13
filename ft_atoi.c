/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:11:12 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/13 20:20:08 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_whitespace_and_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	i = handle_whitespace_and_sign(str, &sign);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (21474836471);
		result = result * 10 + str[i] - '0';
		if ((result * sign) < -2147483648 || (result * sign) > 2147483647)
			return (21474836471);
		i++;
	}
	return (result * sign);
}
