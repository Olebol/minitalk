/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 15:21:28 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/14 19:15:29 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <string.h>

void	chartobin(int pid, char c)
{
	int bin;

	for (int i = 7; i >= 0; i--)
	{
		bin = (1 & (c >> i));
		if (bin == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	(void) argc;
	int pid = atoi(argv[1]);
	char *msg = strdup(argv[2]);

	printf("msg: %s\n", msg);

	for (int i = 0; msg[i] != '\0'; i++)
		chartobin(pid, msg[i]);
	return 0;
}

