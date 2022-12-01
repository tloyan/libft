/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:37:10 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/01 16:37:12 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	if (len == 0 && (!big || !little))
		return (0);
	if (*little == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && len--)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j]
			&& (len + 1 - j))
			j++;
		if (little[j] == '\0')
			return (&((char *)big)[i]);
		i++;
	}
	return (NULL);
}
