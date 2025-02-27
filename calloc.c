/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:57:10 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/02/17 21:57:15 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			byte;
	unsigned char	*str;

	str = s;
	byte = 0;
	while (n--)
	{
		str[byte++] = 0;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	space;
	void	*buff;

	space = count * size;
	if ((count != 0) && ((space / count) != size))
	{
		return (NULL);
	}
	buff = malloc(space);
	if (buff == NULL)
		return (NULL);
	ft_bzero(buff, space);
	return (buff);
}
