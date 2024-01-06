/* ************************************************************************** */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_int(int n);
int		ft_print_unsigned_dec(unsigned int n);
int		ft_print_unsigned_hex(unsigned int num, const char format);
int		ft_print_percent(void);
void	ft_put_ptr(uintptr_t num);
int		ft_ptr_len(uintptr_t num);

#endif