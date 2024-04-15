/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:52:24 by rocky             #+#    #+#             */
/*   Updated: 2024/04/15 18:53:25 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str_array(char **str_list, int count)
{
	int	i;

	i = 0;
	if (str_list)
	{
		while (i < count)
		{
			free(str_list[i]);
			i++;
		}
		free(str_list);
	}
}

void	free_resources(t_Stack *a, t_Stack *b, char **str_list, int count)
{
	free_stack(a);
	free_stack(b);
	if (str_list && count > 0)
		free_str_array(str_list, count);
}

void	initialize_stacks(char **argv, int argc, t_Stack *a, t_Stack *b)
{
	char	**str_list;
	int		count;

	count = parse_arguments(argv, argc, &str_list);
	if (count < 0 || !validate_and_fill_stack(str_list, count, a))
	{
		ft_printf("Error\n");
		free_resources(a, b, str_list, count);
		exit(1);
	}
	determine_sorting_strategy(str_list, a, b, count);
	free_str_array(str_list, count);
}
