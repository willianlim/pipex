/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:56:12 by wrosendo          #+#    #+#             */
/*   Updated: 2021/12/01 09:38:09 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex_shared.h"

static void	*ft_find_path(t_pipex *chest, int k)
{
	int	i;

	i = -1;
	while (!ft_strnstr(chest->envp[++i], PATH, 4))
		;
	chest->paths = ft_split(chest->envp[i], COLON);
	i = -1;
	while (chest->paths[++i])
	{
		chest->path_slash = ft_strjoin(chest->paths[i], FRONT_SLASH);
		free(chest->paths[i]);
		chest->path = ft_strjoin(chest->path_slash, chest->cmd[k][0]);
		free(chest->path_slash);
		if (!access(chest->path, F_OK | X_OK))
		{
			while (chest->paths[++i])
				free(chest->paths[i]);
			free(chest->paths);
			return (chest->path);
		}
		free(chest->path);
	}
	free(chest->paths);
	return (0);
}

int	ft_parse_cmd(t_pipex *chest)
{
	int	j;
	int	i;

	chest->path_exec = (char **)ft_calloc(sizeof(char *), (chest->argc - 2));
	chest->cmd = (char ***)ft_calloc(sizeof(char **), (chest->argc + 1));
	j = -1;
	while (chest->argv[++j] != NULL)
		chest->cmd[j] = ft_split(chest->argv[j], SPACE);
	j = -1;
	i = 0;
	i = chest->j;
	while (++i <= (chest->argc - 3))
	{
		chest->path_exec[++j] = ft_find_path(chest, (i + 1));
		if (chest->path_exec[j] == NULL)
			ft_message_clean(chest, 1, (i + 1));
	}
	return (0);
}
