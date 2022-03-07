/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:23:58 by oaizab            #+#    #+#             */
/*   Updated: 2022/03/07 18:28:54 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(pid_t pid, char *msg)
{
	int		i;
	int		bit;
	char	c;

	i = 0;
	while (msg[i])
	{
		bit = 0;
		c = msg[i];
		while (bit < 8)
		{
			if ((c & 1) == 1)
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			usleep(800);
			c = c >> 1;
			bit++;
		}
		i++;
	}
}
