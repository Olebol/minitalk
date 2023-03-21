/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 20:05:20 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/21 13:38:18 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define ERROR_MSG "An error occured sending the signals\n"

void	ft_error(void)
{
	write(1, ERROR_MSG, sizeof(ERROR_MSG));
	exit(2);
}

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr((n / 10));
	ft_putchar(((n % 10) + '0'));
}
