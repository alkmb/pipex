/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkmb <alkmb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:17:41 by akambou           #+#    #+#             */
/*   Updated: 2023/09/20 15:23:32 by alkmb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*totalstring;
	int		size1;
	int		size2;
	int		i;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	i = 0;
	totalstring = (char *)malloc((size1 + size2 + 1) * sizeof(char));
	if (!totalstring)
		return (NULL);
	size1 = 0;
	while (s1[size1])
	{
		totalstring[size1] = s1[size1];
		size1++;
	}
	while (s2[i])
	{
		totalstring[size1 + i] = s2[i];
		i++;
	}
	totalstring[size1 + i] = '\0';
	return (totalstring);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;
	char	*result;

	str1 = "Hello world boy.";
	str2 = "and fuck you.";
	result = ft_strjoin(str1, str2);
	printf ("This are the both strings joined: %s", result);
}*/
