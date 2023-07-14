/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:21:45 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/20 15:42:28 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *) s + i);
	}
	if (s[i] == (unsigned char)c)
		return ((char *) s + i);
	return (0);
}
