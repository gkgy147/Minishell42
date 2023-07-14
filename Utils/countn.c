/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:20:59 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/19 14:32:00 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//	return: returns the number of occurences of c in str for n chars
//	pro tip: if n is -1 it checks all the string
int	ft_countn(const char *str, const char c, int n)
{
	int	i;

	if (n == -1)
		n = ft_strlen(str);
	i = 0;
	while (str && n > 0)
	{
		if (*str == c)
			i++;
		n--;
		str++;
	}
	return (i);
}
