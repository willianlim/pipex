/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:27 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/30 18:29:38 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "ft_pipex_shared.h"

/**
 * @brief This function creates the pipe, runs the fork and calls the parent
 * and child processes.
 *
 * @param chest Data struct.
 * @return int Exit status/code 0 on success or 2 on error.
 */
static int	ft_pipeline_mandatory(t_pipex *chest);

#endif
