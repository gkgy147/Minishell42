/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:27 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/22 16:18:11 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "./../minishell.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*ptr;

	ptr = (char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
