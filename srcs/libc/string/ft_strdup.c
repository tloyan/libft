/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:36:02 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/01 16:36:04 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		i;

	dst = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(*s));
	if (!dst)
		return (NULL);
	i = 0;
	while (*s)
		dst[i++] = *s++;
	dst[i] = 0;
	return (dst);
}
