/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:23:13 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/20 15:45:41 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	ptr = malloc ((ft_strlen(s1) + 1) * sizeof (char));
	if (!ptr)
		return (0);
	if (!s1)
	{
		ptr[0] = 0;
		return (ptr);
	}
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	ptr[i] = s1[i];
	return (ptr);
}
