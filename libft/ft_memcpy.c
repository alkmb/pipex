/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:16:40 by akambou           #+#    #+#             */
/*   Updated: 2023/09/11 22:16:43 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dd;
	const char	*ss;

	i = 0;
	dd = dst;
	ss = src;
	if (dd == 0 && ss == 0)
		return (NULL);
	while (i < n)
	{
		dd[i] = ss[i];
		i++;
	}
	return (dst);
}
