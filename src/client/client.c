/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:35:59 by oaizab            #+#    #+#             */
/*   Updated: 2022/03/07 18:28:28 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;

	init_signals();
	if (argc == 3)
	{
		pid = parse_pid(argv[1]);
		send_message(pid, argv[2]);
		wait_response(pid);
	}
	else
		ft_printf("Please give 2 arguments!");
	return (0);
}
