/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:16:43 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/20 15:47:14 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	ptr = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!ptr)
		return (0);
	i = -1;
	while (s1 && s1[++i])
		ptr[i] = s1[i];
	j = -1;
	while (s2 && s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = 0;
	return (ptr);
}

char	*gnl_join(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	ptr = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!ptr)
		return (0);
	i = -1;
	while (s1 && s1[++i])
		ptr[i] = s1[i];
	j = -1;
	while (s2 && s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = 0;
	free((void *)s1);
	return (ptr);
}
