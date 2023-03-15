/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 17:17:07 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/15 17:56:06 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n >= 10)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd(((n % 10) + '0'), fd);
}

void	handler(int sig, siginfo_t *client, void *context)
{
	static char	c;
	static int	count;

	(void)	context;
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
		kill(client->si_pid, SIGUSR2);
		count = 0;
		write(1, "\n", 1);
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();

	sig.sa_flags = SA_SIGINFO | SA_NODEFER;
	sig.sa_sigaction = handler;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);

	ft_putstr_fd("Started...\nPID: ", STDOUT_FILENO);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putstr_fd("\n\n", STDOUT_FILENO);

	while (1)
		pause();
	return 0;
}

