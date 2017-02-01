/*
** convert_coords.c for navy in /home/shielder/Projects/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Wed Feb  1 14:46:53 2017 Maxime PICOT
** Last update Wed Feb  1 16:41:28 2017 Maxime PICOT
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
      return (i + 48);
    }
  else if (type == 2)
    {
      coord--;
      if (coord > 8)
	return ('\0');
      return (base[coord]);
    }
  return ('\0');
}
