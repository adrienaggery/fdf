/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 21:34:44 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/29 11:50:56 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 8

typedef struct		s_fd_link
{
	int						fd;
	char					*o_b;
	int						o_b_s;
	struct s_fd_link		*next;
}					t_fd_link;

int					get_next_line(int const fd, char **line);

#endif
