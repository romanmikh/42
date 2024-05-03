#include "fractol.h"

t_complex	ft_init_complex(double real, double imaginary)
{
	t_complex	c;

	c.r = real;
	c.i = imaginary;
	return (c);
}

void	ft_init_env(t_env *env)
{
	env->img = malloc(sizeof(t_img));
	if (!env->img)
		exit(1);
	env->mlx = mlx_init();
	env->img->addr = mlx_new_image(env->mlx, env->size_x, env->size_y);
	env->img->buffer = mlx_get_data_addr(env->img->addr, &env->img->bpp,
			&env->img->line_size, &env->img->endian);
	env->win = mlx_new_window(env->mlx, env->size_x, env->size_y, "fract-ol");
	mlx_hook(env->win, 2, 1L << 0, ft_keypress, env);
	mlx_hook(env->win, 4, 1L << 2, ft_zoom, env);
	mlx_hook(env->win, 15, 1L << 16, ft_minimize, env);
	mlx_hook(env->win, 33, 1L << 5, ft_free_exit, env);
}

int main(int argc, char **argv)
{
  t_env env;

  if (argc == 1)
  {
    ft_printf("I gotta elicit an M or a J from you buddy");
    return (0);
  }
  if (argc > 2)
  {
    ft_printf("You've goaded me into execrating you dildo");
    return (0);
  }
  ft_init_env(&env);
  ft_render(&env);
  mlx.loop(env.mlx); // mini library keep open call
  return (0);
}
