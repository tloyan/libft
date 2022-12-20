/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:07:02 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 15:12:25 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ischarset(const char c, const char *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim_end(char const *s1, char const *set)
{
	char			*ptr;
	unsigned int	len;

	len = ft_strlen(s1);
	while (len > 0 && ischarset(s1[len - 1], set))
		len--;
	ptr = ft_substr(s1, 0, len);
	return (ptr);
}
