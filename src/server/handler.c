/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:57:40 by oaizab            #+#    #+#             */
/*   Updated: 2022/03/07 18:20:18 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sender_pid(siginfo_t *info, t_data *data)
{
	pid_t			new_pid;

	new_pid = info->si_pid;
	if (data->old_pid == 0)
		data->old_pid = new_pid;
	if (data->old_pid != new_pid)
	{
		data->old_pid = new_pid;
		data->bit = 0;
		data->c = 0;
	}
}

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static t_data	data;

	(void) context;
	sender_pid(info, &data);
	if (data.bit < 8)
	{
		if (signum == SIGUSR1)
		{
			data.c += 1 << data.bit;
		}
		data.bit++;
	}
	if (data.bit == 8)
	{
		if (data.c == '\0')
			kill(data.old_pid, SIGUSR1);
		ft_printf("%c", data.c);
		data.bit = 0;
		data.c = 0;
	}
}
