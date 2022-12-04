/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:14:05 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/04 17:45:14 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
