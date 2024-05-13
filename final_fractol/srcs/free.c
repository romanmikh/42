/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:42:52 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/13 16:47:51 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int	ft_free_exit(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img->addr);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->img);
	free(env->mlx);
	exit (0);
	return (1);
}
