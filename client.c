/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:53:01 by jkwak             #+#    #+#             */
/*   Updated: 2022/05/05 20:39:45 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	to_server(pid_t pid, char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = 0x80;
	while(str[i])
	{
		if ((str[i] & c) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		c = c >> 1;
		if (c == 0)
		{
			c = 0x80;
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("too many or too few arguments.\n", 1);
		return (0);
	}
	to_server(ft_atoi(argv[1]), argv[2]);
	return (0);
}