/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <georgerobert147@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:55:51 by gkmon             #+#    #+#             */
/*   Updated: 2023/08/14 11:08:33 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_shell_errno;

int	ft_input_red(t_shell *shell, int n_cmd, int *ind)
{
	if (shell->parsed[n_cmd][*ind] == '<'
		&& !ft_in(shell->parsed[n_cmd][*ind + 1], "><"))
	{
		shell->red.fdin[n_cmd / 2] = ft_get_fd(shell, n_cmd,
				*ind, 'i');
		while (ft_in(shell->parsed[n_cmd][*ind], "><"))
			(*ind)++;
		if (ft_get_filename(shell, n_cmd, ind, 'i'))
			ft_die(shell, 1, 12);
		if (ft_remove_quotes(shell, &shell->red.infiles[n_cmd / 2]))
			ft_die(shell, 1, 12);
		if (access(shell->red.infiles[n_cmd / 2], F_OK | R_OK)
			|| !ft_intab(shell->red.infiles[n_cmd / 2],
				shell->files))
			return (2);
	}
	return (0);
}

int	ft_output_red(t_shell *shell, int n_cmd, int *ind)
{
	int	fd;

	if (shell->parsed[n_cmd][*ind] == '>'
		&& !ft_in(shell->parsed[n_cmd][*ind + 1], "><"))
	{
		shell->red.fdout[n_cmd / 2] = ft_get_fd(shell, n_cmd,
				*ind, 'o');
		while (ft_in(shell->parsed[n_cmd][*ind], "><"))
			(*ind)++;
		ft_free((void **) &shell->red.outfiles[n_cmd / 2]);
		if (ft_get_filename(shell, n_cmd, ind, 'o'))
			ft_die(shell, 1, 12);
		if (ft_remove_quotes(shell, &shell->red.outfiles[n_cmd / 2]))
			ft_die(shell, 1, 12);
		ft_free((void **) &shell->red.afiles[n_cmd / 2]);
		fd = open(shell->red.outfiles[n_cmd / 2],
				O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
		if (fd == -1)
			return (2);
		close(fd);
	}
	return (0);
}

int	ft_append_red(t_shell *shell, int n_cmd, int *ind)
{
	int	fd;

	if (shell->parsed[n_cmd][*ind] == '>'
		&& shell->parsed[n_cmd][*ind + 1] == '>')
	{
		shell->red.fda[n_cmd / 2] = ft_get_fd(shell, n_cmd,
				*ind, 'a');
		while (ft_in(shell->parsed[n_cmd][*ind], "><"))
			(*ind)++;
		ft_free((void **) &shell->red.afiles[n_cmd / 2]);
		if (ft_get_filename(shell, n_cmd, ind, 'a'))
			ft_die(shell, 1, 12);
		if (ft_remove_quotes(shell, &shell->red.afiles[n_cmd / 2]))
			ft_die(shell, 1, 12);
		ft_free((void **) &shell->red.outfiles[n_cmd / 2]);
		fd = open(shell->red.afiles[n_cmd / 2],
				O_CREAT | O_WRONLY,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
		if (fd == -1)
			ft_die(shell, 1, 12);
		close(fd);
	}
	return (0);
}

int	ft_here_doc(t_shell *shell, char *limiter)
{
	int		file;
	char	*temp;

	file = open(".here_doc",
			O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file == -1)
		ft_die(shell, 1, 12);
	temp = ft_read_heredoc_input (file, limiter, temp);
	if (!g_shell_errno)
		close(file);
	if (!temp)
		fd_printf(2, "\nWarning: here-document delimited by end-of-file\n");
	ft_free((void **) &temp);
	return (0);
}

int	ft_hdoc_red(t_shell *shell, int n_cmd, int *ind)
{
	if (shell->parsed[n_cmd][*ind] == '<'
		&& shell->parsed[n_cmd][*ind + 1] == '<')
	{
		shell->red.fdin[n_cmd / 2] = ft_get_fd(shell, n_cmd,
				*ind, 'h');
		while (ft_in(shell->parsed[n_cmd][*ind], "><"))
			(*ind)++;
		if (ft_get_filename(shell, n_cmd, ind, 'h'))
			ft_die(shell, 1, 12);
		if (ft_remove_quotes(shell, &shell->red.infiles[n_cmd / 2]))
			ft_die(shell, 1, 12);
		if (ft_here_doc(shell, shell->red.infiles[n_cmd / 2]))
			ft_die(shell, 1, 12);
		ft_free((void **) &shell->red.infiles[n_cmd / 2]);
		shell->red.infiles[n_cmd / 2] = ft_strdup(".here_doc");
		if (!shell->red.infiles[n_cmd / 2])
			ft_die(shell, 1, 12);
	}
	return (0);
}
