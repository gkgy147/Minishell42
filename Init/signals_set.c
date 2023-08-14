/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <georgerobert147@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:39:43 by gkmon             #+#    #+#             */
/*   Updated: 2023/08/11 17:01:39 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

extern int	g_shell_errno;

void	ft_does_nothing(int signum)
{
	(void)signum;
	return ;
}

void	ft_handle_int(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_shell_errno = 130;
}

// rl_on_new_line();
// rl_redisplay();
void	ft_handle_quit(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

/*
Set up signal handling for the shell.
Get current terminal attributes.
Disable ECHOCTL flag to prevent echoing of control characters.
Apply the modified terminal attributes.
Set signal handlers for SIGINT (Ctrl+C) and SIGQUIT (Ctrl+d).
Set SA_RESTART flag to ensure system calls interrupted by signals 
are automatically restarted after the signal handler returns
*/
void	ft_signals_set(t_shell *shell)
{
	tcgetattr(STDIN_FILENO, &shell->tty_attrs);
	shell->tty_attrs.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &shell->tty_attrs);
	shell->a_nothing.sa_handler = ft_does_nothing;
	shell->a_int.sa_handler = ft_handle_int;
	shell->a_quit.sa_handler = ft_handle_quit;
	shell->a_nothing.sa_flags = SA_RESTART;
	shell->a_int.sa_flags = SA_RESTART;
	shell->a_quit.sa_flags = SA_RESTART;
	sigemptyset(&(shell->a_nothing.sa_mask));
	sigemptyset(&(shell->a_int.sa_mask));
	sigemptyset(&(shell->a_quit.sa_mask));
	sigaction(SIGINT, &shell->a_int, 0);
	sigaction(SIGQUIT, &shell->a_quit, 0);
}
