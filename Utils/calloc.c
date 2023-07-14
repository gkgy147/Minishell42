/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:06:53 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/19 14:27:49 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	*ft_calloc(size_t num, size_t dim)
{
	char	*ptr;
	size_t	i;

	if ((num * dim) / dim != num)
		return (0);
	ptr = (char *) malloc (num * dim);
	if (!ptr)
		return (0);
	i = 0;
	while (i < (num * dim))
		ptr[i++] = 0;
	return ((void *)ptr);
}
