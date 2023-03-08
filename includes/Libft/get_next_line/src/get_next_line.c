/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 19:21:20 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/06 18:50:12 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char	*ft_free(char **ptr);
ssize_t	find_newline(char *str);
char	*divide_lines(char *str);
char	*make_str(int fd, char *str);

char	*get_next_line(int fd)
{
	char			*str;
	static char		*rest;
	char			*new;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	str = NULL;
	if (rest)
	{
		str = ft_strdup(rest);
		ft_free(&rest);
		if (!str)
			return (NULL);
	}
	rest = NULL;
	str = make_str(fd, str);
	if (!str)
		return (NULL);
	rest = divide_lines(str);
	new = ft_strdup(str);
	free(str);
	if (!new)
		return (ft_free(&rest));
	return (new);
}

char	*ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

ssize_t	find_newline(char *str)
{
	ssize_t		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	*divide_lines(char *str)
{
	int		i;
	char	*rest;

	i = find_newline(str) + 1;
	if (str[i - 1] == '\0')
		return (NULL);
	rest = ft_strdup(str + i);
	str[i] = '\0';
	return (rest);
}

char	*make_str(int fd, char *str)
{
	char	buf[BUFFER_SIZE + 1];

	if (!ft_read(fd, buf))
		return (free(str), NULL);
	while (find_newline(buf) == BUFFER_SIZE)
	{
		str = ft_strjoin_free(str, buf);
		if (!str)
			return (NULL);
		if (!ft_read(fd, buf))
			return (str);
	}
	str = ft_strjoin_free(str, buf);
	if (!str)
		return (NULL);
	if (str[0] == '\0')
		return (free(str), NULL);
	return (str);
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	int		file;
// 	char	*str;
// 	int		amount;
// 	if (argc != 3)
// 	{
// 		write(1, "Usage: ./get_next_line [file name] [amount of times]\n", 54);
// 		return (-1);
// 	}
// 	file = open(argv[1], O_RDONLY);
// 	if (file == -1)
// 	{
// 		write(1, "Failed to open file\n", 21);
// 		return (-1);
// 	}
// 	int		count = 0;
// 	amount = atoi(argv[2]);
// 	while (count < amount)
// 	{
// 		str = get_next_line(file);
// 		if (str != NULL)
// 			printf("line %d:\t %s", count + 1, str);
// 		else
// 		{
// 			printf("\nget_next_line failed to execute\n");
// 			break;
// 		}
// 		if (str)
// 			free(str);
// 		count++;
// 	}
// 	close(file);
// 	return 0;
// }
