/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:56:32 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/21 16:59:07 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_params(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argn, char **argv)
{
	int	i;

	i = 1;
	while (i < argn)
	{
		ft_print_params(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
