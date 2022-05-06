/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:54:41 by jkwak             #+#    #+#             */
/*   Updated: 2022/05/06 16:27:27 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	handle_signal(int signum)
{
	static unsigned char	c = 0;
	static int				i = 0;

	if (signum == SIGUSR1)
		c = c | 0;
	else if (signum == SIGUSR2)
		c = c | 1;
	i++;
	if (i < 8)
		c = c << 1;
	else
	{
		ft_putchar_fd(c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("server PID : ", 1);
	ft_putstr_fd(ft_itoa(getpid()), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
}
