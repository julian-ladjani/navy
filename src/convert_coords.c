/*
** convert_coords.c for navy in /home/shielder/Projects/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Wed Feb  1 14:46:53 2017 Maxime PICOT
** Last update Tue Feb 14 03:13:09 2017 julian ladjani
*/

#include "navy.h"

char	my_convertcoords(char coord, int type)
{
  char	*base;
  int	i;

  base = "ABCDEFGH\0";
  i = 0;
  if (type == 1)
    {
      while (base[i] != coord)
	i++;
      return (i + 1 + 48);
    }
  else if (type == 2)
    {
      coord--;
      if (coord > 8)
	return ('\0');
      return (base[i]);
    }
  return ('\0');
}

void            my_coords(char c1, char c2, int *posx, int *posy)
{
  if (is_alpha(c1) && is_num(c2))
    {
      *posx = my_convertcoords(c1, 1) - 48;
      *posy = c2 - 48;
    }
  else if (is_alpha(c2) && is_num(c1))
    {
      *posx = my_convertcoords(c2, 1) - 48;
      *posy = c1 - 48;
    }
}

t_coords	init_coords()
{
  t_coords	coords;

  coords.fx = 0;
  coords.fy = 0;
  coords.lx = 0;
  coords.ly = 0;
  coords.boat = 0;
  return (coords);
}
