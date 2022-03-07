/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:36:40 by oaizab            #+#    #+#             */
/*   Updated: 2022/03/07 18:27:35 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <unistd.h>
# include <signal.h>

typedef struct s_data
{
	pid_t	old_pid;
	char	c;
	int		bit;
}				t_data;

void	confirm_handler(int signum);
void	init_signals(void);
void	wait_response(pid_t pid);
pid_t	parse_pid(char *s_pid);
void	server_handler(int signum, siginfo_t *info, void *context);
void	send_message(pid_t pid, char *msg);

#endif