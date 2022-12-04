/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:13:51 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/04 18:27:02 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s1_len;
	size_t	len;

	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2);
	dst = (char *)malloc((len + 1) * sizeof(*dst));
	if (!dst)
		return (NULL);
	dst[len] = 0;
	dst[s1_len] = 0;
	ft_strlcat(dst, s1, (s1_len + 1));
	ft_strlcat(dst, s2, (len + 1));
	return (dst);
}
