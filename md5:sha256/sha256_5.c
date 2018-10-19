/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 22:42:00 by kykim             #+#    #+#             */
/*   Updated: 2018/10/18 12:54:41 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		sha256_p_md5(int *option)
{
	char	buff[21];
	char	*str;
	int		x;

	str = ft_strnew(0);
	if (!option[4])
	{
		while ((x = read(0, buff, 20)))
		{
			buff[x] = '\0';
			str = joinandsave(str, buff);
		}
	}
	sha256(sha256_prepare(str), option, str);
	free(str);
}

void		sha256_print(u_int32_t *abcd)
{
	ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x",
	abcd[0], abcd[1], abcd[2], abcd[3], abcd[4], abcd[5], abcd[6], abcd[7]);
}

void		sha256_option_three(int *option, u_int32_t *abcd, char *str)
{
	if (option[0])
		sha256_print(abcd);
	else if (option[1])
	{
		sha256_print(abcd);
		ft_printf(" \"%s\"", str);
	}
	else
	{
		ft_printf("SHA256 (\"%s\") = ", str);
		sha256_print(abcd);
	}
}

void		sha256_option_neg_one(int *option, u_int32_t *abcd, char *str)
{
	if (option[0])
		sha256_print(abcd);
	else if (option[1])
	{
		sha256_print(abcd);
		ft_printf(" %s", str);
	}
	else
	{
		ft_printf("SHA256 (%s) = ", str);
		sha256_print(abcd);
		option[4] = 0;
	}
}

void		sha256_option_two_three(int *option, u_int32_t *abcd, char *str)
{
	if (option[0] == 0 && option[1] == 0 &&
	option[2] == 0 && option[3] == 0 && option[4] == 0)
		sha256_print(abcd);
	else if (option[0])
		sha256_print(abcd);
	else if (option[1])
	{
		sha256_print(abcd);
		ft_printf(" %s", str);
	}
	else
	{
		ft_printf("SHA256 (%s) = ", str);
		sha256_print(abcd);
		option[4] = 0;
	}
}
