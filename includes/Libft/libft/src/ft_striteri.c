/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 16:12:35 by opelser       #+#    #+#                 */
/*   Updated: 2022/11/14 17:55:47 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_test(unsigned int i, char *s_char)
// {
// 	i = 32;
// 	*s_char -= i;
// 	printf("s_char : %c |\n", *s_char);
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// int	main(void)
// {
// 	char	str[] = "abcdefgh";

// 	ft_striteri(str, ft_test);
// 	printf("\nend result: %s\n", str);
// }