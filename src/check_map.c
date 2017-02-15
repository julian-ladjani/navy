/*
** check_map.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Wed Feb 15 06:29:32 2017 julian ladjani
** Last update Wed Feb 15 22:46:31 2017 julian ladjani
*/

#include "navy.h"

int     check_victory(t_map *maps)
{
  int	me;
  int	other;

  me = check_map(maps->map, 14);
  other = check_map(maps->omap, 14);
  if (me == 0)
    return (-1);
  else if (other == 0)
    return (1);
  return (0);
}

int	check_map(char **map, int min)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < 8)
    {
      while (j < 8)
	{
          if (map[i][j] == 'x')
            min--;
	  j++;
	}
      j = 0;
      i++;
    }
  if (min <= 0)
    return (0);
  return (1);
}
