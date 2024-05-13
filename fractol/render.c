#include "fractol.h"

void ft_pixel_fix(t_img *img, int colour, int i)
{
  img->buffer[index] = color >> 16 & 0xFF;
	img->buffer[index + 1] = color >> 8 & 0xFF;
	img->buffer[index + 2] = color & 0xFF;
	img->buffer[index + 3] = 0;
}

static void	ft_launch(t_env *env, int i)
{	
	if (env->type == T_JULIA)
		ft_pixel_fix(env->img, ft_julia(env), i);
	else if (env->type == T_MANDEL)
		ft_pixel_fix(env->img, ft_mandelbrot(env), i);
}

int ft_process(t_env *env)
{
  int x;
  int y;
  int i;

  mlx_string_put(env->mlx, env->win, 100, 100, 0xCCCCCC, "Loading");
  i = 0;
  y = 0;
  while (y < env->size_y)
  {
    env->c.i = env->max.i - y * env->factor.i;
    x = 0;
    while (x < env->size_x)
    {
      env->c.r = env->min.r + x * env->factor.r;
      ft_launch(env, i);
      i += 4;
      x++;
    }
    y++;
    ft_printf("\rLoading: [%d%%]", (y * 100) / env->size_y);
  }
  printf("\t\033[1;32mDone\033[0m\n]]");
  return (TRUE);
}

int render(t_env *env)
{
  int real = (env->max.r - env->min.r) / (env->size_x - 1);
  int cplx = (env->max.i - env->min.i) / (env->size_y - 1),
  env->factor = init_cplx(real, cplx);
  
  ft_process(env);
  ft_display(env);
  return (TRUE);
}
