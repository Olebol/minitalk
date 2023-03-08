/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 19:44:08 by opelser       #+#    #+#                 */
/*   Updated: 2022/11/14 22:38:24 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	dst_len = ft_strlen(dst);
	const size_t	src_len = ft_strlen(src);
	size_t			i;

	i = 0;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (i < dstsize - dst_len - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

// #include "libft.h"
// int	main(void)
// {
// 	char	str[30] = "hello ";
// 	char	str2[30] = "world";
// 	size_t	dstsize = 31;

// 	printf("%zu\n", ft_strlcat(str, str2, dstsize));
// 	printf("%s\n", str);

// 	char	str3[30] = "hello ";
// 	char	str4[30] = "world";

// 	printf("\n%zu\n", strlcat(str3, str4, dstsize));
// 	printf("%s\n", str3);
// }