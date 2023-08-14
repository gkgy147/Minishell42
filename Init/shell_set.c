/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <georgerobert147@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:39:13 by gkmon             #+#    #+#             */
/*   Updated: 2023/07/26 08:17:36 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_shell_errno;

int	ft_continue(t_shell *shell, int n)
{
	if (n == 1 && (!shell->line || !shell->line[0]))
	{
		g_shell_errno = 0;
		return (1);
	}
	else if (n == 2 && !shell->parsed)
	{
		g_shell_errno = 0;
		return (2);
	}
	else if (n == 3 && (!shell->parsed || !shell->parsed[0]
			|| !shell->parsed[0][0]))
	{
		g_shell_errno = 0;
		return (3);
	}
	return (0);
}

/*
Set the shell struct variables
*/
void	ft_shell_set(t_shell *shell)
{
	shell->line = 0;
	shell->parsed = 0;
	shell->envp = 0;
	shell->fd_input = 0;
	shell->fd_output = 0;
	shell->lvls = 0;
	shell->n_cmds = 0;
	shell->files = 0;
	shell->pipex.paths = 0;
	shell->red.infiles = 0;
	shell->red.outfiles = 0;
	shell->pipex.pid = 0;
	shell->red.afiles = 0;
	shell->red.fdin = 0;
	shell->red.fdout = 0;
	shell->red.fda = 0;
	shell->exp.pd = 0;
	shell->exp.sp = 0;
	shell->exp.tmp = 0;
	shell->tmp = 0;
	shell->tmp_lvls = 0;
	ft_signals_set(shell);
	shell->envp = list_convert(shell->list, 0);
	if (!shell->envp)
		ft_die(shell, 1, 12);
}
