/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:56:31 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/04/27 12:05:53 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		counter;
	char		*dest;
	char		*srce;

	if (!src && !dst)
		return (0);
	counter = 0;
	dest = (char *)dst;
	srce = (char *)src;
	while (counter < n)
	{
		dest[counter] = (char)srce[counter];
		counter++;
	}
	return (dst);
}
