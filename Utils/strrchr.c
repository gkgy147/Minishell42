/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:44:32 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/20 15:55:32 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	while (--i >= 0)
		if (str[i] == (char)c)
			return ((char *)(str + i));
	return (0);
}
