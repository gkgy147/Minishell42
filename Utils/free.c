/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 07:34:39 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/19 14:41:25 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * Descritpion: enanced free (see stdlib.h) in order to set at NULL the freed
 * 		pointer.
 * input:	the address of the pointer that will be freed casted as (void **).
 * Output:	na.
*/
void	ft_free(void **ptr_addr)
{
	if (!ptr_addr)
		return ;
	free(*ptr_addr);
	*ptr_addr = NULL;
}
