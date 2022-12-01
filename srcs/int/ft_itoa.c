/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:00:00 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/01 18:00:16 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		nlen;
	int		isneg;
	long	nb;
	char	*str;

	nlen = intlen(n);
	isneg = 0;
	nb = (long)n;
	if (nb < 0)
		isneg = 1;
	if (isneg)
		nb = nb * -1;
	str = ft_calloc((nlen + isneg + 1), sizeof(*str));
	if (!str)
		return (NULL);
	if (isneg)
		str[0] = '-';
	while (nlen-- > 0)
	{
		str[nlen + isneg] = ((nb % 10) + '0');
		nb = nb / 10;
	}
	return (str);
}
