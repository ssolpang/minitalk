/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:54:41 by jkwak             #+#    #+#             */
/*   Updated: 2022/05/04 22:37:41 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	print_sigusr(int signum)
{
	static unsigned char	c = 0;
	static unsigned char	temp = 0x80;
	static int				i = 0;

	while (i++ < 8)
	{
	if (signum == SIGUSR1)
	{
		c = c & temp;
		temp = temp > 1;
	}
	else if (signum == SIGUSR2)
	{
		c = c | temp;
		temp = temp > 1;
	}
	if (!temp)
		ft_putchar_fd(c, 1);
	}
	// if (signum == SIGUSR2)
	// 	ft_putchar_fd('1', 1);
	// if (signum == SIGUSR1)
	// 	ft_putchar_fd('0', 1);
}

int	main(void)
{
	ft_putstr_fd("server PID : ", 1);
	ft_putstr_fd(ft_itoa(getpid()), 1);
	ft_putchar_fd('\n', 1);
	
	signal(SIGUSR1, print_sigusr);
	signal(SIGUSR2, print_sigusr);
	
	pause();
	while(1);
}