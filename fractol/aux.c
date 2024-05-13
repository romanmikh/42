#include "fractol.h"

int	ft_is_double(const char *n)
{
	unsigned long	i;
	int				p;

	i = 0;
	while (n[i] && (n[i] == '\t' || n[i] == '\n' || n[i] == '\v'
			|| n[i] == '\f' || n[i] == '\r' || n[i] == ' '))
		i++;
	if (n[i] && (n[i] == '+' || n[i] == '-'))
		i++;
	if (!n[i])
		return (FALSE);
	p = FALSE;
	while (n[i])
	{
		if (!ft_isdigit(n[i]) && n[i] != '.' && n[i] != ',')
			return (FALSE);
		if ((n[i] == '.' || n[i] == ',') && p == TRUE)
			return (FALSE);
		if (n[i] == '.' || n[i] == ',')
			p = TRUE;
		i++;
	}
	return (TRUE);
}

int	ft_is_num(const char *n)
{
	unsigned long	i;

	i = 0;
	while (n[i] && (n[i] == '\t' || n[i] == '\n' || n[i] == '\v'
			|| n[i] == '\f' || n[i] == '\r' || n[i] == ' '))
		i++;
	if (n[i] && (n[i] == '+' || n[i] == '-'))
		i++;
	if (!n[i])
		return (FALSE);
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_no_param(void)
{
	ft_pser("- No parameter entered\nHere is the list of availible option:\n");
	ft_option();
	return (1);
}

void	ft_input(void)
{
	ft_pserc("  - input:\n", "\033[3;37m");
	ft_pserc("scroll up/down:\t\tzoom in/out  ", GRN);
	ft_pserc("(will follow mouse)\n", "\033[1;3;32m");
	ft_pserc("M/N:\t\t\tzoom in/out\n", GRN);
	ft_pserc("WASD/ZQSD/Arrow key:\tmove up/left/down/right\n\n", BMAG);
}

int	ft_option(void)
{
	ft_pserc("\n  - format:\n", "\033[3;37m");
	ft_pserc("./fractol ", BWHI);
	ft_pserc("[TYPE] ", "\033[1;34m");
	ft_pserc("[MAX_ITERATION] ", RED);
	ft_pserc("[REAL] [IMAGINARY]\n", BMAG);
	ft_pserc("\n  - type:\n", "\033[3;34m");
	ft_pserc("./fractol Julia\n  = ./fractol J\n", "\033[1;34m");
	ft_pserc("./fractol Julia_S\n  = ./fractol JS\n", "\033[1;34m");
	ft_pserc("./fractol Mandelbrot\n  = ./fractol M\n", "\033[1;34m");
	ft_pserc("./fractol Mandelbar\n  = ./fractol MB\n", "\033[1;34m");
	ft_pserc("./fractol MA_set\n  = ./fractol MA\n", "\033[1;34m");
	ft_pserc("./fractol Burning_Ship\n  = ./fractol BS\n", "\033[1;34m");
	ft_pserc("\n  - examples:\n", "\033[3;37m");
	ft_pserc("./fractol ", BWHI);
	ft_pserc("M\n", "\033[1;34m");
	ft_pserc("./fractol ", BWHI);
	ft_pserc("BS ", "\033[1;34m");
	ft_pserc("16\n", RED);
	ft_pserc("./fractol ", BWHI);
	ft_pserc("J ", "\033[1;34m");
	ft_pserc("250 ", RED);
	ft_pserc("-0.7 0.27015\n\n", BMAG);
	ft_input();
	return (FALSE);
}

int	ft_has_help(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-h") == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

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
