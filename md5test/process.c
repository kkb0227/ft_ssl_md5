/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 10:02:13 by kykim             #+#    #+#             */
/*   Updated: 2018/09/30 22:42:34 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void switch_order(u_int32_t ABCD[4])
{
	int tmp1;
	int tmp2;
	int tmp3;
	int tmp4;

	tmp1 = ABCD[0];
	tmp2 = ABCD[1];
	tmp3 = ABCD[2];
	tmp4 = ABCD[3];
	ABCD[0] = tmp4;
	ABCD[1] = tmp1;
	ABCD[2] = tmp2;
	ABCD[3] = tmp3;
}

u_int32_t make_lil(u_int32_t X)
{
	u_int32_t a;
	u_int32_t b;
	u_int32_t c;
	u_int32_t d;

	a = X;
	b = X;
	c = X;
	d = X;
	a = (a << 24) & 0xff000000;
	b = (b << 8) & 0x00ff0000;
	c = (c >> 8) & 0x0000ff00;
	d = (d >> 24) & 0x000000ff;
	return (a + b + c + d);
}

void print_result(u_int32_t ABCD[4])
{
	ABCD[0] = make_lil(ABCD[0]);
	ABCD[1] = make_lil(ABCD[1]);
	ABCD[2] = make_lil(ABCD[2]);
	ABCD[3] = make_lil(ABCD[3]);
	ft_printf("%.8x%.8x%.8x%.8x\n", ABCD[0], ABCD[1], ABCD[2], ABCD[3]);
}