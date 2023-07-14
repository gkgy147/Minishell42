/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:23:29 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/20 15:54:17 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (i < n - 1)
	{
		if (s1[i] != s2[i] || !s1[i])
			break ;
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
