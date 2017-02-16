/*
** my_navy.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Thu Feb  2 15:11:52 2017 julian ladjani
** Last update Thu Feb 16 03:07:50 2017 julian ladjani
*/

#include "navy.h"

int	the_navy_game_p2(t_map *map)
{
  char	*pos;

  g_game.mode = RECPOSX;
  his_turn(map);
  if ((value = check_victory(map)) != 0)
    return (value);
  pos = my_turn(map);
  while (g_game.mode != NONE);
  g_game.mode = RECHIT;
  check_hit(map, pos);
  return (check_victory(map));
}

int	the_navy_game_p1(t_map *map)
{
  char	*pos;
  int	value;

  pos = my_turn(map);
  while (g_game.mode != NONE);
  g_game.mode = RECHIT;
  check_hit(map, pos);
  if ((value = check_victory(map)) != 0)
    return (value);
  g_game.mode = RECPOSX;
  his_turn(map);
  return (0);
}

int	the_game_loop(t_map *map)
{
  int   value;

  value = 0;
  if (g_game.poshit[3] == 1)
    {
      write_play(map->map, map->omap);
      while ((value = the_navy_game_p1(map)) == 0);
    }
  else if (g_game.poshit[3] == 2)
    {
      while ((value = the_navy_game_p2(map)) == 0);
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
    {
      my_printf("I won\n");
      return (0);
    }
  if (value == -1)
    {
      my_printf("Enemy won\n");
      return (1);
    }
  my_printf("ERROR WON\n");
  return (84);
}
