/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 15:21:28 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/21 13:37:36 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define RECEIVED_MSG "The message has been received!\n"
#define INVALID_ARG_MSG "Invalid arguments\n"

int		g_signal_received;

void	char_to_bin(int pid, char c)
{
	int		bin;
	int		check;
	int		i;

	i = 7;
	while (i >= 0)
	{
		bin = (1 & (c >> i));
		if (bin == 0)
			check = kill(pid, SIGUSR1);
		else
			check = kill(pid, SIGUSR2);
		if (check == -1)
			ft_error();
		while (!g_signal_received)
			;
		g_signal_received = 0;
		i--;
	}
}

void	received_handler(int sig)
{
	(void) sig;
	g_signal_received = 1;
}

void	succesful_handler(int sig)
{
	(void) sig;
	write(1, RECEIVED_MSG, sizeof(RECEIVED_MSG));
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		i;
	int		pid;

	i = 0;
	if (argc != 3)
		return (write(1, INVALID_ARG_MSG, sizeof(INVALID_ARG_MSG)), 1);
	if (!is_digit(argv[1]))
		return (write(1, INVALID_ARG_MSG, sizeof(INVALID_ARG_MSG)), 1);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, &received_handler);
	signal(SIGUSR2, &succesful_handler);
	while (argv[2][i] != '\0')
	{
		char_to_bin(pid, argv[2][i]);
		i++;
	}
	char_to_bin(pid, 0);
	return (0);
}
