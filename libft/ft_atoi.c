/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:18:54 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/11/27 15:41:23 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	num;
	int	sign;

	a = 0;
	num = 0;
	sign = 0;
	while (str[a] == 32 || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			sign++;
		a++;
	}
	while (str[a] && (str[a] >= '0' && str[a] <= '9'))
	{
		num = num * 10 + (str[a] - '0');
		a++;
	}
	if (sign % 2 == 1)
		return (num * -1);
	return (num);
}
