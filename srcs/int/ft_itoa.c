/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:00:00 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/04 18:13:50 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		is_negative;
	char	*str;

	len = ft_intlen(n);
	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	str = (char *)malloc((len + is_negative + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	str[len + is_negative] = 0;
	if (n == INT_MIN)
		return ((ft_strlcpy(str, "-2147483648", 12)), str);
	if (is_negative)
	{
		n = n * -1;
		str[0] = '-';
	}
	while (len-- > 0)
	{
		str[len + is_negative] = ((n % 10) + '0');
		n = n / 10;
	}
	return (str);
}
