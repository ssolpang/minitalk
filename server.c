/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:54:41 by jkwak             #+#    #+#             */
/*   Updated: 2022/05/05 20:40:50 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	print_sigusr(int signum)
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
	
	signal(SIGUSR1, print_sigusr);
	signal(SIGUSR2, print_sigusr);
	
	while(1)
		pause();
}