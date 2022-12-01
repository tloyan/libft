/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:13:51 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/01 17:13:52 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)ft_calloc(len + 1, sizeof(*dst));
	if (!dst)
		return (NULL);
	ft_strlcat(dst, s1, (len + 1));
	ft_strlcat(dst, s2, (len + 1));
	return (dst);
}
