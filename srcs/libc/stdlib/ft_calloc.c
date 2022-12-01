/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:50:57 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/01 16:51:12 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			n;
	void			*ptr;

	n = (nmemb * size);
	if (size && (n / size) != nmemb)
		return (NULL);
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, n);
	return (ptr);
}
