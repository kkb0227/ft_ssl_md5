/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 22:55:47 by kykim             #+#    #+#             */
/*   Updated: 2018/10/18 17:04:59 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	sha256_without_flag(char *str, int option[5])
{
	char	buff[1024];
	int		fd;
	int		readsize;
	char	*result;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ft_ssl: sha256: %s: %s\n", str, strerror(errno));
		return ;
	}
	result = ft_strnew(0);
	while ((readsize = read(fd, buff, 1024)))
	{
		buff[readsize] = '\0';
		result = joinandsave(result, buff);
	}
	option[4] = -1;
	close(fd);
	sha256(sha256_prepare(result), option, result);
	free(result);
}

int		sha256_s_md5(int i, int j, char **argv, int *option)
{
	char	*str;
	int		len;
	int		x;

	len = 0;
	x = 0;
	if (argv[i][j + 1] == '\0')
	{
		str = ft_strdup(argv[i + 1]);
		i += 1;
	}
	else
		str = argv_to_str(i, j, argv);
	sha256(sha256_prepare(str), option, str);
	free(str);
	return (i);
}

void	sha256_abcd_init(u_int32_t abcd[8])
{
	abcd[0] = 0x6a09e667;
	abcd[1] = 0xbb67ae85;
	abcd[2] = 0x3c6ef372;
	abcd[3] = 0xa54ff53a;
	abcd[4] = 0x510e527f;
	abcd[5] = 0x9b05688c;
	abcd[6] = 0x1f83d9ab;
	abcd[7] = 0x5be0cd19;
}
