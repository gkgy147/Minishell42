/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_until.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:23:16 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/20 15:53:14 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen_until(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i] && !ft_in(str[i], set))
		i++;
	return (i);
}