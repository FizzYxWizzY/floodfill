/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 05:39:34 by mflury            #+#    #+#             */
/*   Updated: 2024/08/08 06:39:26 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void print_map(char **map) {
	int i = 0;

    printf("\033[2J");
    printf("\033[H");
	while (i < 10) {
		printf("%s\n", map[i++]);
	}
	sleep(1);
}

void floodfill(char **map, int posy, int posx) {
	if (map[posy][posx] == 1 || map[posy][posx] == 'X')
		return ;
	map[posy][posx] = 'X';
	print_map(map);
	if (posy != 10)
		floodfill(map, posy + 1, posx);
	if (posx != 10)
		floodfill(map, posy, posx + 1);
	if (posy != 0)
		floodfill(map, posy - 1, posx);
	if (posx != 0)
		floodfill(map, posy, posx - 1);
}

int	main() {
	int i = 0;
	char **map = malloc(sizeof(char *) * 10);
	while (i < 10)
		map[i++] = malloc(sizeof(char *) * 10);
	map[0] = "1111111111";
	map[1] = "1000000001";
	map[2] = "100100s001";
	map[3] = "1001111111";
	map[4] = "1001000001";
	map[5] = "1001001001";
	map[6] = "1001111001";
	map[7] = "1000001001";
	map[8] = "1010100001"; 
	map[9] = "1111111111";
	print_map(map);

	floodfill(map, 2, 6);

	free(map);
	return 0;
}
