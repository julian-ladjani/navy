/*
** write_game.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Sun Feb 12 00:33:04 2017 julian ladjani
** Last update Thu Feb 16 00:56:20 2017 julian ladjani
*/

#include "navy.h"

void	write_map(char **map)
{
  int	i;

  i = 0;
  my_printf(" |A B C D E F G H\n");
  my_printf("-+---------------\n");
  while (map[i] != NULL)
    {
      my_printf("%d|%c %c", i + 1, map[i][0], map[i][1]);
      my_printf(" %c %c %c %c", map[i][2], map[i][3], map[i][4], map[i][5]);
      my_printf(" %c %c\n", map[i][6], map[i][7]);
      i++;
    }
}

void	write_play(char **map, char **omap)
{
  my_printf("my positions:\n");
  write_map(map);
  my_printf("\n");
  my_printf("enemy's positions:\n");
  write_map(omap);
  my_printf("\n");
}
