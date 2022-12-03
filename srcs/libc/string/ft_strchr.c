/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:35:50 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/03 03:16:03 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;

	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i = i + 1;
	}
	return (NULL);
}
