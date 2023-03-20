/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 20:20:37 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/20 20:31:45 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

// ~ utils.c

size_t		ft_strlen(const char *str);
void		ft_putstr(char *s);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_error(void);

#endif