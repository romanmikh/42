/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:48:14 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/13 16:48:19 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_args(t_god *god, int ac, char **av)
{
	if (ac == 5 && (ft_is_num(av[2]) == FALSE || ft_is_double(av[3]) == \
		FALSE || ft_is_double(av[4]) == FALSE))
	{
		ft_printf("Some non-numeric Julia arguments passed\n");
		return (0);
	}
	if (ac == 3)
	{
		god->ite = ft_atoi(av[2]);
		if (god->ite <= 0)
			god->ite = 1;
	}
	else if (ac == 5)
	{
		god->ite = ft_atoi(av[2]);
		if (god->ite <= 0)
			god->ite = 1;
		god->julia_c = init_cplx(ft_atof(av[3]), ft_atof(av[4]));
	}
	else
	{
		god->julia_c = init_cplx(-0.7, 0.27);
		god->ite = 250;
	}
	return (TRUE);
}

static int	set_fractal_type(t_god *god, char **av)
{
	god->type = 0;
	if (ft_strcmp(av[1], "J") == 0 || ft_strcmp(av[1], "Julia") == 0)
		god->type = T_JULIA;
	else if (ft_strcmp(av[1], "M") == 0 || ft_strcmp(av[1], "Mandelbrot") == 0)
		god->type = T_MANDEL;
	else if (ft_strcmp(av[1], "MB") == 0 || ft_strcmp(av[1], "Mandelbar") == 0)
		god->type = T_MB;
	else if (ft_strcmp(av[1], "BS") == 0
		|| ft_strcmp(av[1], "Burning_Ship") == 0)
		god->type = T_BS;
	else
		return (FALSE);
	return (TRUE);
}

int	handle_args(t_god *god, int ac, char **av)
{
	if (julia_args(god, ac, av) == FALSE)
		return (FALSE);
	if (set_fractal_type(god, av) == FALSE)
	{
		ft_printf("Incorrect fractal type provided.\n");
		return (0);
	}
	init_defaults(god);
	return (TRUE);
}
