/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:37:46 by adelille          #+#    #+#             */
/*   Updated: 2021/10/26 15:42:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(t_god *god)
{
	t_cplx	z;
	int			i;

	z.r = god->c.r;
	z.i = god->c.i;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < god->ite)
	{
		z = init_cplx(z.r * z.r - z.i * z.i + god->k.r,
				2 * z.r * z.i + god->k.i);
		i++;
	}
	return (ft_red_to_black(colour_bitwise_encode(
				255 - 255 * ((god->ite - i) * (god->ite - i))
				% (god->ite * god->ite), 0, 0)));
}
