/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:09:51 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/01 17:10:10 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static char	*nextword(char const *s, char c, int *cur)
{
	int		i;
	int		wlen;
	char	*w;

	i = 0;
	wlen = 0;
	while (s[*cur] == c && s[*cur] != 0)
		*cur = *cur + 1;
	while (s[*cur + wlen] != c && s[*cur + wlen] != 0)
		wlen++;
	w = ft_calloc(wlen + 1, sizeof(*w));
	if (!w)
		return (NULL);
	while (i < wlen)
	{
		w[i] = s[*cur + i];
		i++;
	}
	w[i] = 0;
	*cur = *cur + wlen;
	return (w);
}

static void	*ft_free_arr(void **ptrs, size_t n)
{
	while (n--)
		free(ptrs[n]);
	free(ptrs);
	return (NULL);
}

// TODO : Rework ft_split with ft_strdup && ft_substr 
char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		n;
	int		i;
	int		cursor;

	n = wordcount(s, c);
	strs = ft_calloc(n + 1, sizeof(*strs));
	if (!strs)
		return (NULL);
	i = 0;
	cursor = 0;
	while (i < n)
	{
		strs[i] = nextword(s, c, &cursor);
		if (!strs[i])
			return (ft_free_arr((void **)strs, i));
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
