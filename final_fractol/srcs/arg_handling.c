/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:48:14 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/13 16:48:19 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_cplx_arg(t_god *god, int ac, char **av)
{
	god->k.r = REAL;
	god->k.i = IMAGINARY;
	if (ac > 2 && ft_is_num(av[2]) == FALSE)
		return (0);
	if (ac > 2)
	{
		god->ite = ft_atol(av[2]);
		if (god->ite <= 0)
			god->ite = 1;
	}
	if (ac >= 5
		&& (ft_is_double(av[3]) == FALSE || ft_is_double(av[4]) == FALSE))
		return (0);
	if (ac >= 5)
	{
		god->k.r = ft_atof(av[3]);
		god->k.i = ft_atof(av[4]);
	}
	return (TRUE);
}

static int	handle_args_fractal(t_god *god, char **av)
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
	if (handle_args_fractal(god, av) == FALSE)
		return (0);
	ft_default(god);
	if (ft_cplx_arg(god, ac, av) == FALSE)
		return (FALSE);
	return (TRUE);
}
