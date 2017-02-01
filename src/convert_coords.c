/*
** my_printf_fonc_base.c for my_printf in /home/julian-ladjani/delivery/PSU/my_printf/PSU_2016_my_printf/src/fonction
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Sat Nov 12 17:51:57 2016 julian ladjani
<<<<<<< HEAD
** Last update Wed Feb  1 14:17:05 2017 Maxime PICOT
=======
** Last update Wed Feb  1 14:42:25 2017 julian ladjani
>>>>>>> 8772e775d877eb292dead66f5546bec31ff364e4
*/

#include "my.h"

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
      return (base[i]);
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
