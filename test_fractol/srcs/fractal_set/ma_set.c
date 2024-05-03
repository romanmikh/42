/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:09:06 by adelille          #+#    #+#             */
/*   Updated: 2021/10/22 19:24:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_ma_set(t_env *env)
{
	t_complex	c;
	double		tmp;
	int			i;

	c.r = env->c.r;
	c.i = env->c.i;
	i = 0;
	while (c.r * c.r + c.i * c.i - 12 < 4 && i < env->ite)
	{
		tmp = c.i + c.r * c.r - c.i * c.i + env->c.r - env->k.r;
		c.i = 2 * c.r * c.i + env->c.i - env->k.i;
		c.r = tmp;
		i++;
	}
	return (ft_red_to_black(ft_ints_to_int(
				255 - 255 * ((env->ite - i) * (env->ite - i))
				% (env->ite * env->ite), 0, 0)));
}
