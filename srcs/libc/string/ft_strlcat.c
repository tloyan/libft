/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:36:17 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/01 16:36:18 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dl;
	unsigned int	sl;

	if (size == 0 && (!dst || !src))
		return (0);
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (size <= dl)
		return (size + sl);
	while (*(src) && ((size--) - dl - 1))
		*((dst++) + dl) = *src++;
	*(dst + dl) = 0;
	return (dl + sl);
}
