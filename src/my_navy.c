/*
** my_navy.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Thu Feb  2 15:11:52 2017 julian ladjani
** Last update Wed Feb 15 23:22:47 2017 julian ladjani
*/

#include "navy.h"

void    the_navy_game_p2(t_map *map)
{
  g_game.mode = RECPOSX;
  his_turn(map);
  my_turn(map);
  g_game.mode = RECHIT;
  check_hit(map);
}

void    the_navy_game_p1(t_map *map)
{
  my_turn(map);
  g_game.mode = RECHIT;
  check_hit(map);
  g_game.mode = RECPOSX;
  his_turn(map);
}

int     the_game_loop(t_map *map)
{
  int   value;

  value = 0;
  if (g_game.poshit[3] == 1)
    {
      while ((value = check_victory(map)) == 0)
	the_navy_game_p1(map);
    }
  else if (g_game.poshit[3] == 2)
    {
      while ((value = check_victory(map)) == 0)
        the_navy_game_p2(map);
    }
  return (value);
}

int	the_game(char **map, char **omap)
{
  t_map	maps;
  int	value;

  maps.map = map;
  if ((omap = my_setmap()) == NULL)
    return (84);
  maps.omap = omap;
  value = the_game_loop(&maps);
  if (value == 1)
    return (0);
  if (value == -1)
    return (1);
  else
    return (84);
}
