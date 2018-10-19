/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 10:02:13 by kykim             #+#    #+#             */
/*   Updated: 2018/10/17 12:09:50 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		switch_order(u_int32_t abcd[4])
{
	int tmp1;
	int tmp2;
	int tmp3;
	int tmp4;

	tmp1 = abcd[0];
	tmp2 = abcd[1];
	tmp3 = abcd[2];
	tmp4 = abcd[3];
	abcd[0] = tmp4;
	abcd[1] = tmp1;
	abcd[2] = tmp2;
	abcd[3] = tmp3;
}

u_int32_t	make_lil(u_int32_t x)
{
	u_int32_t a;
	u_int32_t b;
	u_int32_t c;
	u_int32_t d;

	a = x;
	b = x;
	c = x;
	d = x;
	a = (a << 24) & 0xff000000;
	b = (b << 8) & 0x00ff0000;
	c = (c >> 8) & 0x0000ff00;
	d = (d >> 24) & 0x000000ff;
	return (a + b + c + d);
}

void		print_result(u_int32_t abcd[4])
{
	abcd[0] = make_lil(abcd[0]);
	abcd[1] = make_lil(abcd[1]);
	abcd[2] = make_lil(abcd[2]);
	abcd[3] = make_lil(abcd[3]);
	ft_printf("%.8x%.8x%.8x%.8x", abcd[0], abcd[1], abcd[2], abcd[3]);
}
