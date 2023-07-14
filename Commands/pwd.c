/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:23:12 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/22 16:05:31 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	print_pwd(t_shell *shell)
{
	char	*str;

	str = getcwd(0, 0);
	if (!str)
		ft_die(shell, 1, 12);
	printf("%s\n", str);
	free(str);
	return (0);
}