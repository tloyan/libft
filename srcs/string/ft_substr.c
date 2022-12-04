/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:14:54 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/04 17:44:20 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*dst;
	long unsigned int	maxlen;

	maxlen = ft_strlen(s) - start;
	if (start >= (unsigned int)ft_strlen(s))
		maxlen = 0;
	if (len < maxlen)
		maxlen = len;
	dst = (char *)malloc((maxlen + 1) * sizeof(*dst));
	if (!dst)
		return (NULL);
	dst[maxlen] = 0;
	while (maxlen--)
		dst[maxlen] = s[start + maxlen];
	return (dst);
}
