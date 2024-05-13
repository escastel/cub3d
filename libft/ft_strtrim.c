/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:28:38 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/05/01 15:38:35 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	count;
	size_t	counter;

	count = 0;
	len = ft_strlen(s1);
	counter = len;
	if (!s1 || !set)
		return (0);
	if (*s1 == '\0' && len == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[count]))
		count++;
	while (ft_strrchr(set, s1[counter]))
		counter--;
	return (ft_substr(s1, count, counter - count + 1));
}
