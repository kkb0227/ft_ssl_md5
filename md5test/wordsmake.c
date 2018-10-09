/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordsmake.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 10:38:23 by kykim             #+#    #+#             */
/*   Updated: 2018/09/30 22:41:50 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

u_int32_t **make_words(int block_num)
{
	u_int32_t **words;
	int i;

	i = 0;
	words = malloc(sizeof(u_int32_t *) * (block_num + 1));
	while (i < block_num)
	{
		words[i] = malloc(sizeof(u_int32_t) * 16);
		ft_bzero(words[i], 16);
		i++;
	}
	words[block_num] = NULL;
	return (words);
}

void    fill_the_words(u_int32_t **words, unsigned char **block)
{
	int i;
	int j;
	int temp;

	i = 0;
	temp = 0;
	while (block[i] != NULL)
	{
		j = 0;
		while (j < 64)
		{
			if (j % 4 == 3)
				temp += block[i][j] << 24;
			else if (j % 4 == 2)
				temp += block[i][j] << 16;
			else if (j % 4 == 1)
				temp += block[i][j] << 8;
			else if (j % 4 == 0)
				temp += block[i][j];
			if (j % 4 == 3)
			{
				words[i][j / 4] = temp;
				temp = 0;
			}
            j++;
	    }
	    i++;
    }
}

void    add_length(const char *str, u_int32_t **words)
{
	int i;
	long long int len;

	i = 0;
	len = 8 * ft_strlen(str);
	while (words[i] != '\0')
		i++;
	i -= 1;
	words[i][14] = len;
	words[i][15] = (len & 0xffffffff00000000) >> 32;
}
