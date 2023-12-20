/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:01:29 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/17 21:10:06 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>
char	*ft_strlowcase(char *str)
{
	char	*i;

	i = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str = *str + 32;
		}
		str++;
	}
	return (i);
}
/*
int	main(void)
{
	// can't pass string, must be a variable (pointers)
	char	zzz[] = "JHIUfyytfRYFRY HyghjbY7 ,P";
	printf("%s", ft_strlowcase(zzz));
	return (0);
	}*/
