/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 11:07:54 by kykim             #+#    #+#             */
/*   Updated: 2018/10/18 17:02:45 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	free_block(unsigned char **block)
{
	int i;

	i = 0;
	while (block[i])
	{
		free(block[i]);
		i++;
	}
	free(block[i]);
	free(block);
}

void	zero(int option[5])
{
	option[0] = 0;
	option[1] = 0;
	option[2] = 0;
	option[3] = 0;
	option[4] = 0;
}

void	print_error(void)
{
	ft_printf("Error : \'s\' option needs [string]\n");
	exit(1);
}

void	sha256_assign(u_int32_t **words, unsigned char **block, int i)
{
	int temp;
	int j;

	temp = 0;
	j = 0;
	while (j < 64)
	{
		if (j % 4 == 0)
			temp += block[i][j] << 24;
		else if (j % 4 == 1)
			temp += block[i][j] << 16;
		else if (j % 4 == 2)
			temp += block[i][j] << 8;
		else if (j % 4 == 3)
			temp += block[i][j];
		if (j % 4 == 3)
		{
			words[i][j / 4] = temp;
			temp = 0;
		}
		j++;
	}
}

void	without_flag(char *str, int option[5])
{
	char	buff[1024];
	int		fd;
	int		readsize;
	char	*result;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ft_ssl: md5: %s: %s\n", str, strerror(errno));
		return ;
	}
	result = ft_strnew(0);
	while ((readsize = read(fd, buff, 1024)))
	{
		buff[readsize] = '\0';
		result = joinandsave(result, buff);
	}
	close(fd);
	option[4] = -1;
	md5_calculation(prepare(result), option, str);
	free(result);
}
