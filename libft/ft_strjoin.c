/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:17:41 by akambou           #+#    #+#             */
/*   Updated: 2023/11/15 16:16:10 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*totalstring;
	int		size1;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen(s1);
	i = 0;
	totalstring = (char *)malloc((size1 + ft_strlen(s2) + 1) * sizeof(char));
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
