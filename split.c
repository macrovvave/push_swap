/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-mos <hoel-mos@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:59:33 by hoel-mos          #+#    #+#             */
/*   Updated: 2025/02/13 13:59:55 by hoel-mos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_fill(const char *s, int *i)
{
	char	*buff;
	int		o;
	int		count;
	int		y;

	while ((s[*i] == ' ') && s[*i])
		(*i)++;
	count = 0;
	y = *i;
	while ((s[*i] != ' ') && s[*i])
	{
		(*i)++;
		count++;
	}
	buff = ft_calloc(sizeof(char), count + 1);
	if (!buff)
		return (NULL);
	o = 0;
	while (s[y + o] && s[y + o] != ' ')
	{
		buff[o] = s[y + o];
		o++;
	}
	buff[o] = '\0';
	return (buff);
}

static int	ft_count(const char *s)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == ' ')
			index++;
		if (s[index] != ' ' && s[index])
		{
			count++;
			while (s[index] != ' ' && s[index])
			{
				index++;
			}
		}
	}
	return (count);
}

static void	*ft_fre(char **buff, int d)
{
	while (--d >= 0)
		free(buff[d]);
	free(buff);
	return (NULL);
}

char	**ft_split(char *s)
{
	int		d;
	int		index;
	char	**buffer;

	if (!s || !*s)
		return (NULL);
	d = ft_count(s);
	buffer = ft_calloc(sizeof(char *), (d + 1));
	if (buffer == NULL)
		return (NULL);
	index = 0;
	d = 0;
	while (s[index])
	{
		while (s[index] == ' ')
			index++;
		if (s[index] && s[index] != ' ')
		{
			buffer[d] = ft_fill(s, &index);
			if (!buffer[d++])
				return (ft_fre(buffer, d));
		}
	}
	buffer[d] = 0;
	return (buffer);
}
