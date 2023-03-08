/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:54:06 by opelser       #+#    #+#                 */
/*   Updated: 2022/11/14 18:40:20 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = b;
	i = 0;
	while (len > i)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str2[50] = "This is a test sentence to check for memset";
//     printf("Before actual memset(): %s\n", str2);
//     memset(NULL + 13, '.', 2*sizeof(int));
//     printf("After memset():  %s\n\n\n", str2);

// 	char str[50] = "This is a test sentence to check for memset";
//     printf("\nBefore my memset(): %s\n", str);
//     ft_memset(NULL + 13, '.', 2*sizeof(int));
// 	printf("After memset():  %s", str);

//     return 0;
// }