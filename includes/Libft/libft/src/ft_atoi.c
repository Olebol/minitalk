/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 17:06:26 by opelser       #+#    #+#                 */
/*   Updated: 2022/11/14 20:11:04 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	The atoi() function converts the initial portion of the string
		pointed to by nptr to int. The converted value or 0 on error.
*/

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	int		result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// #include "libft.h"
// int	main()
// {
// 	const char	str[] = "2147483649";

// 	printf("%d\n", ft_atoi(str));

// 	printf("%d", atoi(str));
// }