/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:29:22 by bcarlee           #+#    #+#             */
/*   Updated: 2021/12/06 12:51:21 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_error(char *text)
{
	printf("Error\n%s", text);
	return (0);
}

void	print_error(char *text)
{
	printf("Error\n%s", text);
	exit (0);
}

void	game_over(void)
{
	printf("Game_over\n");
	exit (0);
}
