/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 21:00:35 by opelser       #+#    #+#                 */
/*   Updated: 2022/11/14 18:21:23 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void		*org;
	size_t		i;

	org = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (n > i)
	{
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (org);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char str[20] = "wassup homeboy";
// 	char str2[20] = "nothing much";

// 	printf("My memcpy:\n%s\n\n", ft_memcpy(((void *)0), ((void *)0), 3));

// 	char str3[20] = "wassup homeboy";
// 	char str4[20] = "nothing much";

// 	printf("Actual memcpy:\n%s\n\n", memcpy(((void *)0), ((void *)0), 3));
// }