/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:35:24 by oaizab            #+#    #+#             */
/*   Updated: 2022/03/07 18:21:51 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.__sigaction_u.__sa_handler = confirm_handler;
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &sa, NULL);
}

pid_t	parse_pid(char *s_pid)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (s_pid[i])
	{
		if (s_pid[i] > '9' || s_pid[i] < '0')
		{
			ft_putendl_fd("Invalid PID number", 2);
			exit(1);
		}
		i++;
	}
	pid = ft_atoi(s_pid);
	if (pid == 0)
	{
		ft_putendl_fd("Invalid PID number", 2);
		exit(1);
	}
	return (pid);
}
