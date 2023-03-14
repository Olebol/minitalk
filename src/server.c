/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 17:17:07 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/14 19:45:56 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int displayed = 0;
int c = 0;

void handler(int sig)
{
	displayed++;
}

void handler2(int sig)
{
	c |= 1;
	displayed++;
}

int	main(void)
{
	int pid;

	pid = getpid();
	printf("Started...\nPID: %d\n\n", pid);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler2);
	while (1)
	{
		c <<= 1;
		pause();
		if (displayed == 8)
		{
			printf("%c < \n", (char) c);
			displayed = 0;
			c = 0;
		}
	}
	exit (0);
	return 0;
}

