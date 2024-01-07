/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <rmikhayl@student.42london.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:47:44 by rocky             #+#    #+#             */
/*   Updated: 2024/01/07 15:47:44 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdio.h>

int	main()
{
    // Hexadecimal Lowercase (x)
    ft_printf("%x\n", 0);
    printf("%x\n", 0);

    ft_printf("%x\n", 255);
    printf("%x\n", 255);

    ft_printf("%x\n", -1);
    printf("%x\n", -1);

    // Hexadecimal Uppercase (X)
    ft_printf("%X\n", 0);
    printf("%X\n", 0);

    ft_printf("%X\n", 255);
    printf("%X\n", 255);

    ft_printf("%X\n", -1);
    printf("%X\n", -1);

    // Pointer (p)
    int a = 10;
    ft_printf("%p\n", &a);
    printf("%p\n", &a);

    ft_printf("%p\n", NULL);
    printf("%p\n", NULL);

    // String (s)
    ft_printf("%s\n", "Hello, world!");
    printf("%s\n", "Hello, world!");

    ft_printf("%s\n", "");
    printf("%s\n", "");
    
    // Character (c)
    ft_printf("%c\n", 'A');
    printf("%c\n", 'A');

    ft_printf("%c\n", 65);
    printf("%c\n", 65);

    ft_printf("%c\n", '\0');
    printf("%c\n", '\0');

    // Decimal Integer (d)
    ft_printf("%d\n", 123);
    printf("%d\n", 123);

    ft_printf("%d\n", -123);
    printf("%d\n", -123);

    ft_printf("%d\n", 0);
    printf("%d\n", 0);

    // Unsigned Decimal Integer (u)
    ft_printf("%u\n", 123);
    printf("%u\n", 123);

    ft_printf("%u\n", -123);
    printf("%u\n", -123);

    ft_printf("%u\n", 0);
    printf("%u\n", 0);

    // Percent Sign (%)
    ft_printf("%%\n");
    printf("%%\n");

	return (0);
}
