/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:50:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/28 22:58:16 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#include "libft.h"

extern char	**environ;

int	set_input_redirection(const char *file_name)
{
	int	fd;

	if (file_name == NULL)
		return (0);
	if (access(file_name, F_OK) < 0)
		return (-1);
	if (access(file_name, R_OK) < 0)
		return (-1);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (dup2(fd, STDIN_FILENO) < 0)
		return (-1);
	return (1);
}

int	set_output_redirection(const char *file_name)
{
	int	fd;

	if (file_name == NULL)
		return (0);
	if (access(file_name, F_OK) < 0)
		fd = open(file_name, O_WRONLY | O_CREAT, 0644);
	else if (access(file_name, W_OK) < 0)
		return (-1);
	else
		fd = open(file_name, O_WRONLY | O_TRUNC);
	if (fd < 0)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (-1);
	return (1);
}

int	parse_command(char ***argv, char *command)
{
	*argv = ft_split(command, ' ');
	if (!*argv)
		return (-1);
	return (1);
}

int	find_path(char **path, char *cmd, const char **env_path)
{
	char	*path_tmp;

	while (*env_path)
	{
		path_tmp = ft_strjoin(*env_path, cmd);
		if (path_tmp == NULL)
			return (-1);
		if (access(path_tmp, F_OK) == 0)
		{
			if (access(path_tmp, X_OK) < 0)
			{
				free(path_tmp);
				return (-1);
			}
			*path = path_tmp;
			return (1);
		}
		free(path_tmp);
		env_path++;
	}
	return (-1);
}

int	ft_execve(char *command, \
		const char **env_path, \
		const char *input_redirection, \
		const char *output_redirection)
{
	char		**argv;
	char		*path;

	if (set_input_redirection(input_redirection) < 0)
	{
		perror(command);
		exit(errno);
	}
	if (set_output_redirection(output_redirection) < 0)
	{
		perror(command);
		exit(errno);
	}
	if (parse_command(&argv, command) < 0)
	{
		perror(command);
		exit(errno);
	}
	if (find_path(&path, argv[0], env_path) < 0)
	{
		perror(command);
		exit(errno);
	}
	execve(path, argv, environ);
	return (0);
}
