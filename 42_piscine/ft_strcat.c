/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:32:49 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/19 20:51:12 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	j;

	j = 0;
	while (*str++)
	{
		j++;
	}
	return (j);
}

char	*ft_strcat(char *dest, char *str)
{
	int	i;
	int	destlen;

	i = 0;
	destlen = ft_strlen(dest);
	while (str[i])
	{
		dest[destlen + i] = str[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (dest);
}
/*     


int	main(void)
{
	char	dest[] = "ABC";
	char	str[] = "abc";
	
	printf("%s", ft_strcat(dest, str));
	return (0);
}*/
