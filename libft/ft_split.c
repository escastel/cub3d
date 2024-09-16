/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:03:45 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/16 13:36:09 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

static void	ft_free(char **str, int ind)
{
	while (ind-- > 0)
		free(str[ind]);
	free(str);
}

static int	ft_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		ind;

	i = 0;
	ind = -1;
	str = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	while (++ind < ft_count(s, c))
	{
		while (s[i] == c)
			i++;
		str[ind] = ft_substr(s, i, ft_len(s, c, i));
		if (!(str[ind]))
		{
			ft_free(str, ind);
			return (0);
		}
		i += ft_len(s, c, i);
	}
	str[ind] = 0;
	return (str);
}
