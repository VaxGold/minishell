/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:40:39 by abello-r          #+#    #+#             */
/*   Updated: 2022/02/11 18:06:52 by adiaz-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	char	x;

	if (!s)
		return ;
	i = 0;
	while (i != ft_strlen(s))
	{
		x = s[i];
		write(fd, &x, 1);
		i++;
	}
	write(fd, "\n", 1);
}
