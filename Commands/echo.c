/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 05:01:05 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/22 16:01:02 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	arg_check(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	print_cmd(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\"')
			while (cmd[++i] != '\"')
				printf("%c", cmd[i]);
		else if (cmd[i] == '\'')
			while (cmd[++i] != '\'')
				printf("%c", cmd[i]);
		else
			printf("%c", cmd[i]);
		i++;
	}
}

void	print_arg(char **cmd, int i, int flag)
{
	while (cmd[i])
	{
		print_cmd(cmd[i]);
		if (cmd[i + 1])
			printf(" ");
		i++;
	}
	if (flag == 0)
		return ;
	else
		printf("\n");
}

int	echo(char **argv)
{
	int		i;
	int		flag;
	char	**cmd;

	i = 1;
	cmd = line_filter(argv);
	if (!cmd[i])
	{
		printf("\n");
		ft_free_mat((void ***) &cmd);
		return (0);
	}
	if (!ft_strncmp(cmd[i], "-n", 2) && arg_check(cmd[i]))
	{
		flag = 0;
		i++;
		while (cmd[i] && !ft_strncmp(cmd[i], "-n", 2) && arg_check(cmd[i]))
			i++;
	}
	else
		flag = 1;
	print_arg(cmd, i, flag);
	ft_free_mat((void ***) &cmd);
	return (0);
}
