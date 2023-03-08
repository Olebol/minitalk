/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 18:53:44 by opelser       #+#    #+#                 */
/*   Updated: 2022/11/14 17:51:39 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && dstsize != 0 && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}

// #include "libft.h"
// int	main(void)
// {
// 	char	str[] = "123456789";
// 	char	str2[] = "abcdefghi";

// 	printf("%zu\n", ft_strlcpy(str, str2, 0));
// 	printf("%s\n", str);

// 	char	str3[] = "123456789";
// 	char	str4[] = "abcdefghi";

// 	printf("\n%zu\n", strlcpy(str3, str4, 0));
// 	printf("%s\n", str3);
// }