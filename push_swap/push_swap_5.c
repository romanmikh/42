
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

void	free_resources(Stack *stack_a, Stack *stack_b, char **str_list, int count)
{
	free_stack(stack_a);
	free_stack(stack_b);
	if (str_list && count > 0)
		free_str_array(str_list, count);
}

void	initialize_stacks(char **argv, int argc, Stack *stack_a, Stack *stack_b)
{
	char	**str_list;
	int		count;

	count = parse_arguments(argv, argc, &str_list);
	if (count < 0 || !validate_and_fill_stack(str_list, count, stack_a))
	{
		printf("Error\n");
		free_resources(stack_a, stack_b, str_list, count);
		exit(1);
	}
	determine_sorting_strategy(str_list, stack_a, stack_b, count);
	free_str_array(str_list, count);
}
