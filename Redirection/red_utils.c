/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <georgerobert147@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:06:19 by gkmon             #+#    #+#             */
/*   Updated: 2023/08/14 11:11:24 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_shell_errno;

int	ft_strlen_without(char *str, char *set)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (!ft_in(str[i], set))
			len++;
		i++;
	}
	return (len);
}

char	*ft_null_to_str(char *ptr)
{
	if (!ptr)
		ptr = ft_strdup("");
	return (ptr);
}

int	ft_fill_red(t_shell *shell)
{
	int	i;

	i = 0;
	while (i < shell->n_cmds)
	{
		shell->red.infiles[i] = ft_null_to_str(shell->red.infiles[i]);
		if (!shell->red.infiles[i])
			ft_die(shell, 1, 12);
		shell->red.outfiles[i] = ft_null_to_str(shell->red.outfiles[i]);
		if (!shell->red.outfiles[i])
			ft_die(shell, 1, 12);
		shell->red.afiles[i] = ft_null_to_str(shell->red.afiles[i]);
		if (!shell->red.afiles[i])
			ft_die(shell, 1, 12);
		i++;
	}
	return (0);
}

int	ft_intab(char *str, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(str, tab[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read_heredoc_input(int file, char *limiter, char *temp)
{
	g_shell_errno = 0;
	while (1)
	{
		write(1, "heredoc> ", 9);
		temp = get_next_line(0);
		if (!temp || (!ft_strncmp(temp, limiter, ft_strlen(limiter))
				&& ft_strlen(temp) == ft_strlen(limiter) + 1))
			break ;
		if (g_shell_errno)
			break ;
		write(file, temp, ft_strlen(temp));
		free(temp);
	}
	if (g_shell_errno == 130)
	{
		file = open(".here_doc", O_WRONLY | O_TRUNC);
		close(file);
		fd_printf(2, "ctl+c\n");
	}
	return (temp);
}
