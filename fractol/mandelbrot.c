#include "fractol.h"

int	ft_mandelbrot(t_env *env)
{
	t_complex	c;
	double		tmp;
	int			i;

	c.r = env->c.r;
	c.i = env->c.i;
	i = 0;
	while (c.r * c.r + c.i * c.i < 4 && i < env->ite)
	{
		tmp = c.r * c.r - c.i * c.i + env->c.r;
		c.i = 2 * c.r * c.i + env->c.i;
		c.r = tmp;
		i++;
	}

  int ints = ft_ints_to_int(255 - 255 * ((env->ite - i) * (env->ite - i)));
  int to_black = ft_red_to_black(ints % (env->ite * env->ite), 0, 0);
	return (to_black);
}
