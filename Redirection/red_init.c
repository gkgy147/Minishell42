/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:44:25 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/19 13:55:31 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_set_rarray(t_shell *shell)
{
	int	i;

	i = 0;
	while (i < shell->n_cmds)
	{
		shell->red.fdout[i] = 1;
		shell->red.fda[i] = 1;
		i++;
	}
}

void	ft_allocate_rarray(t_shell *shell)
{
	shell->files = ft_readdir("./");
	if (!shell->files)
		ft_die(shell, 1, 12);
	shell->red.infiles = (char **)ft_calloc(sizeof(char *),
			shell->n_cmds + 1);
	if (!shell->red.infiles)
		ft_die(shell, 1, 12);
	shell->red.outfiles = (char **)ft_calloc(sizeof(char *),
			shell->n_cmds + 1);
	if (!shell->red.outfiles)
		ft_die(shell, 1, 12);
	shell->red.afiles = (char **)ft_calloc(sizeof(char *),
			shell->n_cmds + 1);
	if (!shell->red.afiles)
		ft_die(shell, 1, 12);
	shell->red.fdin = (int *)ft_calloc(sizeof(int), shell->n_cmds);
	if (!shell->red.fdin)
		ft_die(shell, 1, 12);
	shell->red.fdout = (int *)ft_calloc(sizeof(int), shell->n_cmds);
	if (!shell->red.fdout)
		ft_die(shell, 1, 12);
	shell->red.fda = (int *)ft_calloc(sizeof(int), shell->n_cmds);
	if (!shell->red.fda)
		ft_die(shell, 1, 12);
	ft_set_rarray(shell);
}
