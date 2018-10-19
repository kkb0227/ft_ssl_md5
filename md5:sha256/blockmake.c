/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blockmake.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 10:27:17 by kykim             #+#    #+#             */
/*   Updated: 2018/10/17 12:00:03 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned char	**block_make(const char *str, int blocknum[1])
{
	int				i;
	int				len;
	unsigned char	**block;

	i = 0;
	len = ft_strlen(str);
	while (len >= ((64 * i) + 56))
		i++;
	blocknum[0] = i + 1;
	block = malloc(sizeof(unsigned char *) * (blocknum[0] + 1));
	block[blocknum[0]] = NULL;
	i = 0;
	while (i < blocknum[0])
	{
		block[i] = malloc(sizeof(unsigned char) * 64);
		ft_bzero(block[i], 64);
		i++;
	}
	return (block);
}

void			fill_block(const char *str, unsigned char **block)
{
	int i;
	int j;

	i = 0;
	if (!str[i])
		block[0][0] = 128;
	else
	{
		while (str[i] != '\0')
		{
			j = 0;
			while (j < 64 && str[i] != '\0')
			{
				block[i / 64][j] = str[i];
				j++;
				i++;
			}
			if (str[i] == '\0')
				block[i / 64][j] = 128;
		}
	}
}
