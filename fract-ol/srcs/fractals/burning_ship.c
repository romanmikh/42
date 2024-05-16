/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:57:32 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/15 13:57:40 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_burning_ship(t_god *god)
{
	t_cplx		c;
	double		tmp;
	int			i;

	c.r = god->c.r;
	c.i = god->c.i;
	i = 0;
	while (c.r * c.r + c.i * c.i < 4 && i < god->ite)
	{
		tmp = c.r * c.r - c.i * c.i + god->c.r;
		c.i = -2.0 * fabs(c.r * c.i) + god->c.i;
		c.r = tmp;
		i++;
	}
	return (discont_to_black(
			255 - 255 * ((god->ite - i) * (god->ite - i) * (god->ite - i))
			% (god->ite * god->ite * god->ite)));
}
