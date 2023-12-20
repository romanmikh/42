/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:04:28 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/19 22:59:37 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
char	*ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
int     main()
{
        char s1[] = "Flaviano";
        char s2[] = "Octavio";

        

        printf("s1: %s s2: %s\n", s1, s2);
        strncpy(s1, s2, 5);
        printf("s1: %s s2: %s", s1, s2);
        return (0);
}*/
