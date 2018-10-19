/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:56:18 by kykim             #+#    #+#             */
/*   Updated: 2018/10/18 11:57:57 by kykim            ###   ########.fr       */
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

void		option_neg_one(int *option, u_int32_t *checksum, char *str)
{
	if (option[0])
		print_result(checksum);
	else if (option[1])
	{
		print_result(checksum);
		ft_printf(" %s", str);
	}
	else
	{
		ft_printf("MD5 (%s) = ", str);
		print_result(checksum);
		option[4] = 0;
	}
}

void		option_three(int *option, u_int32_t *checksum, char *str)
{
	if (option[0])
		print_result(checksum);
	else if (option[1])
	{
		print_result(checksum);
		ft_printf(" \"%s\"", str);
	}
	else
	{
		ft_printf("MD5 (\"%s\") = ", str);
		print_result(checksum);
	}
}

void		option_two_three(int *option, u_int32_t *checksum, char *str)
{
	if (option[0] == 0 && option[1] == 0 &&
	option[2] == 0 && option[3] == 0 && option[4] == 0)
		print_result(checksum);
	else if (option[0])
		print_result(checksum);
	else if (option[1])
	{
		print_result(checksum);
		ft_printf(" %s", str);
	}
	else
	{
		ft_printf("MD5 (%s) = ", str);
		print_result(checksum);
		option[4] = 0;
	}
}

void		md5_calculation(u_int32_t **words, int *option, char *str)
{
	u_int32_t abcd[4];
	u_int32_t *checksum;

	abcd[0] = 0x67452301;
	abcd[1] = 0xefcdab89;
	abcd[2] = 0x98badcfe;
	abcd[3] = 0x10325476;
	checksum = rounds(abcd, words);
	if (option[2])
	{
		ft_printf("%s", str);
		print_result(checksum);
	}
	else if (option[4] == -1)
		option_neg_one(option, checksum, str);
	else if (option[3])
		option_three(option, checksum, str);
	else if (option[2] == 0 && option[3] == 0)
		option_two_three(option, checksum, str);
	ft_printf("\n");
	free_words(words);
}
