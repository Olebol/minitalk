/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 17:17:07 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/20 20:43:21 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *client, void *context)
{
	static char	c;
	static int	count;

	(void) context;
	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;
	count++;
	if (count == 8 && c)
	{
		write(1, &c, 1);
		count = 0;
		c = 0;
	}
	else if (count == 8 && !c)
	{
		if (kill(client->si_pid, SIGUSR2) == -1)
			ft_error();
		count = 0;
		write(1, "\n", 1);
	}
	if (kill(client->si_pid, SIGUSR1) == -1)
		ft_error();
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	sig.sa_flags = SA_SIGINFO | SA_NODEFER;
	sig.sa_sigaction = handler;
	sigemptyset(&sig.sa_mask);
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		return (1);
	ft_putstr("Started...\nPID: ");
	ft_putnbr(pid);
	ft_putstr("\n\n");
	while (1)
		pause();
	return (0);
}
