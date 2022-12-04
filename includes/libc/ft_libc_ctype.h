/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc_ctype.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:34:26 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/04 17:36:34 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBC_CTYPE_H
# define FT_LIBC_CTYPE_H

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif