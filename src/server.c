/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 17:17:07 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/13 19:28:33 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int sig)
{
	printf("received signal: %d\n", sig);
}

int	main(void)
{
	int pid;

	pid = getpid();
	printf("Started...\nPID: %d\n\n", pid);
	signal(SIGUSR1, &handler);
	while (1)
		pause();
	return 0;
}

