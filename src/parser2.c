/*
** parser2.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Feb 14 02:28:52 2017 julian ladjani
** Last update Tue Feb 14 12:55:49 2017 julian ladjani
*/

#include "navy.h"

char	**set_map_x(t_coords *coords, char **map)
{
  int	diff;
  int	start;
  int	end;

  if (coords->lx > coords->fx &&
      (diff = coords->lx - coords->fx + 1) == coords->boat)
    {
      start = coords->fx - 1;
      end = coords->lx - 1;
    }
  else if (coords->fx > coords->lx &&
      (diff = coords->fx - coords->lx + 1) == coords->boat)
    {
      start = coords->lx - 1;
      end = coords->fx - 1;
    }
  else
    return (NULL);
  while (start <= end && map[coords->ly][end] != '\0')
    {
      map[coords->ly - 1][start] = coords->boat + 48;
      start++;
    }
  return (map);
}

char	**set_map_y(t_coords *coords, char **map)
{
  int	diff;
  int	start;
  int	end;

  if (coords->ly > coords->fy &&
      (diff = coords->ly - coords->fy + 1) == coords->boat)
    {
      start = coords->fy - 1;
      end = coords->ly - 1;
    }
  else if (coords->fy > coords->ly &&
      (diff = coords->fy - coords->ly + 1) == coords->boat)
    {
      start = coords->ly - 1;
      end = coords->fy - 1;
    }
  else
    return (NULL);
  while (start <= end && map[end] != NULL)
    {
      map[start][coords->lx - 1] = coords->boat + 48;
      start++;
    }
  return (map);
}

int	check_boat(char **map, int boat)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (map[i] != NULL)
    {
      while (map[i][j] != '\0')
	{
	  if (map[i][j] == (boat + 48))
	    return (1);
	  j++;
	}
      j = 0;
      i++;
    }
  return (0);
}

char	**coord_in_map(t_coords coords, char **map)
{
  if (coords.lx > 0 && coords.ly > 0 && coords.fx > 0
      && coords.fy > 0 && coords.boat > 1 &&
      coords.lx < 9 && coords.ly < 9 && coords.fx < 9
      && coords.fy < 9 && coords.boat < 6 &&
      check_boat(map, coords.boat) == 0)
    {
      if (coords.lx != coords.fx && coords.fy == coords.ly)
	map = set_map_x(&coords, map);
      else if (coords.lx == coords.fx && coords.fy != coords.ly)
	map = set_map_y(&coords, map);
      else
	return (NULL);
    }
  else
    return (NULL);
  return (map);
}
