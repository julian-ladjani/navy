/*
** write_game.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Sun Feb 12 00:33:04 2017 julian ladjani
** Last update Sun Feb 19 17:34:30 2017 julian ladjani
*/

#include "navy.h"

void	write_map(char **map)
{
  int	i;

  i = 0;
  my_putstr(" |A B C D E F G H\n");
  my_putstr("-+---------------\n");
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
  my_putstr("my positions:\n");
  write_map(map);
  my_putstr("\n");
  my_putstr("enemy's positions:\n");
  write_map(omap);
  my_putstr("\n");
}
