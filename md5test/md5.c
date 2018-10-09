/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:56:18 by kykim             #+#    #+#             */
/*   Updated: 2018/09/30 22:42:54 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

u_int32_t	**prepare(const char *str)
{
	u_int32_t		**words;
	unsigned char	**block;
	int				blocknum[1];

	block = block_make(str, blocknum);
	fill_block(str, block);
	words = make_words(blocknum[0]);
	fill_the_words(words, block);
	add_length(str, words);
	free_block(block);
	return (words);
}

void md5_calculation(u_int32_t **words, char *option, char *str)
{
	u_int32_t ABCD[4];
	u_int32_t *checksum;

	ABCD[0] = 0x67452301;
	ABCD[1] = 0xefcdab89;
	ABCD[2] = 0x98badcfe;
	ABCD[3] = 0x10325476;
	checksum = rounds(ABCD, words);
	if (!check_option('q', option))
		print_result(checksum);
	else
	{
		if (check_option('r', option))
		{
			if (!check_option('p', option))
			{
				ft_printf("%s", str);
				print_result(checksum);
			}
			else
			{
			ft_printf("MD5 (\"%s\") = ", str);
			print_result(checksum);
			}
		}
		else
		{
			if (!check_option('p', option))
			{
				ft_printf("%s", str);
				print_result(checksum);
			}
			else
			{
				print_result(checksum);
				ft_printf("\"%s\"\n", str);
			}
		}
	}
}

void print_by_flag(char *option, u_int32_t *checksum, char *str)
{
	if (!check_option('p', option))
	{
		ft_printf("%s", str);
		print_result(checksum);
	}
}