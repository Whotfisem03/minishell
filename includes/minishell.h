/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:57:48 by engo              #+#    #+#             */
/*   Updated: 2022/12/11 13:33:33 by vloth            ###   ########.fr       */
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

//typedef struct s_token
//{
//	
//}	t_token;

typedef struct s_cmd
{
	char 			*cmd;
	struct t_cmd	*back;
	struct t_cmd	*next;
}	t_cmd;

typedef struct t_data
{
	int 			nbcmd;
	int				nbpipe;
	t_cmd			*begin;
	t_cmd			*end;
}	t_data;


void	check_builtin(char *str, char **envp);
int		tab_count(char **str);
void	built_pwd(void);
t_data	*init_parsing(char *str);
void	init_one_cmd(t_data *data, char *str);

#endif