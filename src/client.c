/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 15:21:28 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/13 19:11:34 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	(void) argc;
	int pid = atoi(argv[1]);

	kill(pid, SIGUSR1);
	return 0;
}

// void sighandler_usr1(int sig)
// {
	
// }