/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:36:53 by adelille          #+#    #+#             */
/*   Updated: 2021/10/22 16:19:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbar(t_god *god)
{
	t_cplx	c;
	double		tmp;
	int			i;

	c.r = god->c.r;
	c.i = god->c.i;
	i = 0;
	while (c.r * c.r + c.i * c.i < 4 && i < god->ite)
	{
		tmp = c.r * c.r - c.i * c.i + god->c.r;
		c.i = -2.0 * c.r * c.i + god->c.i;
		c.r = tmp;
		i++;
	}
	return (discont_to_black(colour_bitwise_encode(
				255 - 255 * ((god->ite - i) * (god->ite - i))
				% (god->ite * god->ite), 0, 0)));
}
