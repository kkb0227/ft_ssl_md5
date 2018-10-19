# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kykim <kykim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/09 11:53:48 by kykim             #+#    #+#              #
#    Updated: 2018/10/17 21:20:43 by kykim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

CFILES = *.c

OFILES = *.o

CGFLAGS = -Wall -Wextra -Werror

LIBFT = library/ft_libft

PRINTF = library/ft_printf

GNL = library/Get_Next_Line

all: $(NAME)

$(NAME):
		make -C $(LIBFT)
		make -C $(GNL)
		make -C $(PRINTF)
		gcc $(CGFLAGS) -c $(CFILES) -I.
		gcc $(OFILES) -L $(LIBFT) -lft -L $(GNL) -lgnl -L $(PRINTF) -lftprintf -o $(NAME)

clean:
	make -C $(LIBFT)/ clean
	make -C $(GNL)/ clean
	make -C $(PRINTF)/ clean
	rm -f $(OFILES)

fclean: clean
		make -C $(LIBFT)/ fclean
		make -C $(GNL)/ fclean
		make -C $(PRINTF)/ fclean
		rm -f $(NAME)

re: fclean all

.PHONY: re all fclean clean