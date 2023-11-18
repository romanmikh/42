/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:56:32 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/22 20:28:03 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

char	**ft_sort_args(int argn, char **argv)
{
	int		i;
	char	*swap;
	int		flag;

	i = 1;
	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		while (i < argn - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				swap = argv[i + 1];
				argv[i + 1] = argv[i];
				argv[i] = swap;
				flag = 1;
			}
			i++;
		}
		i = 1;
	}
	return (argv);
}

int	main(int argn, char **argv)
{
	int		i;
	char	**reorder_args;

	i = 1;
	reorder_args = ft_sort_args(argn, argv);
	while (i < argn)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
