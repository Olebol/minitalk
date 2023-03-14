/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 17:17:07 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/14 22:54:12 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *client, void *context)
{
	(void)		context;
	static char	c;
	static int	count;

	c <<= 1;
	if (kill(client->si_pid, 0) == -1)
		exit(1);
	if (sig == SIGUSR2)
		c |= 1;
	count++;
	if (count == 8 && c)
	{
		printf("%c", c);
		count = 0;
		c = 0;
	}
	else if (count == 8 && !c)
	{
		kill(client->si_pid, SIGUSR2);
		count = 0;
		printf("\n");
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);

	printf("Started...\nPID: %d\n\n", pid);

	while (1)
		pause();
	return 0;
}

