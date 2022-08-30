/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:50:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/30 00:02:57 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

#include "libft.h"

extern char	**environ;

int		ft_execve(char *command, \
		const char **env_path, \
		const char *input_redirection, \
		const char *output_redirection);
char	**get_path(char **envp);
int		exe_pipe(char *command, const char **env_path, \
		const char *input_redirection, \
		const char *output_redirection);

int	main(int argc, char **argv)
{
	const char	*env_path[] = {
		"/bin/", "/sbin/", "/usr/bin/", "/usr/sbin/", NULL};
	int			argi;

	if (argc < 5)
		return (0);
	if (exe_pipe(argv[2], env_path, argv[1], NULL) < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	argi = 3;
	while (argi < argc - 2)
	{
		if (exe_pipe(argv[argi++], env_path, NULL, NULL) < 0)
		{
			perror(argv[0]);
			exit(-1);
		}
	}
	if (exe_pipe(argv[argc - 2], env_path, NULL, argv[argc - 1]) < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	return (0);
}	

int	exe_pipe(char *command, const char **env_path, \
		const char *input_redirection, \
		const char *output_redirection)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		close(STDOUT_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		return (ft_execve(command, env_path, \
				input_redirection, output_redirection));
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
	}
	return (0);
}
