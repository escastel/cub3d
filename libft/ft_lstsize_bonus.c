/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:19:05 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/05/03 19:03:05 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*actual;

	if (!lst)
		return (0);
	i = 1;
	actual = lst;
	while (actual->next)
	{
		i++;
		actual = actual->next;
	}
	return (i);
}
