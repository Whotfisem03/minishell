/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:57:48 by engo              #+#    #+#             */
/*   Updated: 2022/12/07 01:08:50 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include "libft.h"

typedef struct s_gen
{
	char	**envp;
}			 t_gen;


void	check_builtin(char *str, char **envp);
int		tab_count(char **str);



#endif