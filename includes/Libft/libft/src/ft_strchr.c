/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 19:33:52 by opelser       #+#    #+#                 */
/*   Updated: 2022/11/14 18:13:18 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if (*s == (char) c)
		return ((char *)s);
	return (NULL);
}

// #include "libft.h"
// int	main(void)
// {
// 	const char	s[] = "this is the string that's being looked through";
// 	printf("return ft_strchr: \t|%s|\n", ft_strchr(s, 'r'));
// 	printf("return strchr: \t\t|%s|\n", strchr(s, 'r'));
// }