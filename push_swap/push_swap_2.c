/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:43:23 by rocky             #+#    #+#             */
/*   Updated: 2024/04/15 18:44:45 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_two_args(char **argv, char ***str_list)
{
	*str_list = ft_split(argv[1], ' ');
	return (list_len_str(*str_list));
}

int	handle_multiple_args(int argc, char **argv, char ***str_list)
{
	int	i;

	*str_list = malloc((argc - 1) * sizeof(char *));
	if (!*str_list)
		return (-1);
	i = 0;
	while (i < argc - 1)
	{
		(*str_list)[i] = ft_strdup(argv[i + 1]);
		if (!(*str_list)[i])
		{
			while (i-- > 0)
				free((*str_list)[i]);
			free(*str_list);
			return (-1);
		}
		i++;
	}
	return (argc - 1);
}

int	parse_arguments(char **argv, int argc, char ***str_list)
{
	if (argc == 2)
		return (handle_two_args(argv, str_list));
	else
		return (handle_multiple_args(argc, argv, str_list));
}

int	validate_and_fill_stack(char **str_list, int count, t_Stack *stack_a)
{
	int	i;

	i = count - 1;
	while (i >= 0)
	{
		if (isnum_from_str(str_list[i]) == 0 || \
			is_within_int_range(str_list[i]) == 0 || \
			arr_of_str_has_repeats(str_list, count) == 1)
		{
			return (0);
		}
		push(stack_a, atoi(str_list[i]));
		i--;
	}
	return (1);
}
