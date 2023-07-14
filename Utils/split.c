/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:22:53 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/20 15:40:07 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	ft_strnbr(char const *str, char chr)
{
	int		c;

	while (*str && *str == chr)
		str++;
	c = 0;
	while (*str)
	{
		if (*str == chr)
		{
			while (*str == chr && *str)
				str++;
			c++;
		}
		else
			str++;
	}
	if (*(--str) == chr && c)
		c--;
	return (c);
}

char	**ft_fill(char const *s, char c)
{
	char	**ptr;
	int		j;
	int		k;

	ptr = (char **) ft_calloc((ft_strnbr(s, c) + 2), sizeof (char *));
	if (!ptr)
		return (0);
	k = 0;
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c && ++j)
				s++;
			ptr[k++] = ft_substr(s - j, 0, j);
		}
		else
			s++;
	}
	ptr[k] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s || !c)
		if (!s)
			return (0);
	if (!(*s))
	{
		ptr = (char **) malloc (2 * sizeof (char *));
		ptr[0] = 0;
		ptr[1] = 0;
	}
	else
		ptr = ft_fill(s, c);
	return (ptr);
}
