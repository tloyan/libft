/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:14:39 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/01 17:14:40 by thloyan          ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ptr;
	unsigned int	start;
	unsigned int	len;

	start = 0;
	len = ft_strlen(s1);
	while (s1[start] && ischarset(s1[start], set))
		start++;
	while (len > 0 && ischarset(s1[len - 1], set))
		len--;
	len = len - start;
	ptr = ft_substr(s1, start, len);
	return (ptr);
}
