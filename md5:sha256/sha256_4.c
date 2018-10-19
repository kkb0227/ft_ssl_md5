/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:55:44 by kykim             #+#    #+#             */
/*   Updated: 2018/10/18 17:24:45 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

const		u_int32_t g_sha256_hash[64] =
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
	0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
	0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
	0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152,
	0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
	0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
	0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08,
	0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f,
	0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void		sha256_shift(u_int32_t abcd[8], u_int32_t temp1, u_int32_t temp2)
{
	abcd[7] = abcd[6];
	abcd[6] = abcd[5];
	abcd[5] = abcd[4];
	abcd[4] = abcd[3] + temp1;
	abcd[3] = abcd[2];
	abcd[2] = abcd[1];
	abcd[1] = abcd[0];
	abcd[0] = temp1 + temp2;
}

void		copy_abcd(u_int32_t origabcd[8], u_int32_t abcd[8])
{
	int i;

	i = 0;
	while (i < 8)
	{
		origabcd[i] = abcd[i];
		i++;
	}
}

u_int32_t	*sha256_rounds(u_int32_t abcd[8], u_int32_t *word)
{
	int			i;
	u_int32_t	temp1;
	u_int32_t	temp2;
	u_int32_t	origabcd[8];

	i = 0;
	copy_abcd(origabcd, abcd);
	while (i < 64)
	{
		temp1 = abcd[7] + s1(abcd[4]) + ch(abcd[4], abcd[5], abcd[6])
		+ g_sha256_hash[i] + word[i];
		temp2 = s0(abcd[0]) + maj(abcd[0], abcd[1], abcd[2]);
		sha256_shift(abcd, temp1, temp2);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		abcd[i] += origabcd[i];
		i++;
	}
	return (abcd);
}

void		sha256(u_int32_t **words, int *option, char *str)
{
	int			i;
	u_int32_t	abcd[8];

	sha256_abcd_init(abcd);
	i = 0;
	while (words[i])
	{
		copy_abcd(abcd, sha256_rounds(abcd, words[i]));
		i++;
	}
	if (option[2])
	{
		ft_printf("%s", str);
		sha256_print(abcd);
	}
	else if (option[4] == -1)
		sha256_option_neg_one(option, abcd, str);
	else if (option[3])
		sha256_option_three(option, abcd, str);
	else if (option[2] == 0 && option[3] == 0)
		sha256_option_two_three(option, abcd, str);
	ft_printf("\n");
	free_words(words);
}
