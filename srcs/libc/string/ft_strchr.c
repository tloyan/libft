/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:35:50 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/01 16:35:51 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;

	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i] != (unsigned char)c && s[i] != 0)
		i++;
	if (i == ft_strlen(s))
		return ((void *)0);
	return ((char *)&s[i]);
}
