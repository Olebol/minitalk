/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 15:21:28 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/14 22:22:54 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int signal_received;

void	chartobin(int pid, char c)
{
	int bin;

	for (int i = 7; i >= 0; i--)
	{
		signal_received = 0;
		bin = (1 & (c >> i));
		if (bin == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (!signal_received)
			pause();
	}
}

void received_handler(int sig)
{
	signal_received = 1;
}

void succesful_handler(int sig)
{
	printf("The message has been received!\n");
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	int pid = atoi(argv[1]);

	signal(SIGUSR1, &received_handler);
	signal(SIGUSR2, &succesful_handler);

	for (int i = 0; argv[2][i] != '\0'; i++)
		chartobin(pid, argv[2][i]);
	chartobin(pid, 0);
	return 0;
}

