/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloyan <tloyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:08:38 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 13:26:43 by tloyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *nptr)
{
	long int	res;
	long int	sign;

	res = 0;
	sign = 1;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr && (*nptr == '-' || *nptr == '+'))
	{
		if (*nptr == '-')
			sign = sign * -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		res = (res * 10) + (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}
