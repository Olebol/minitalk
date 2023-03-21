/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 13:24:36 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/21 13:28:01 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	is_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}
