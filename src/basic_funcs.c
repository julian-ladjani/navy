/*
** basic_funcs.c for navy in /home/shielder/Projects/PSU/PSU_2016_navy
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Thu Feb  2 14:00:20 2017 Maxime PICOT
** Last update Thu Feb 16 02:52:06 2017 julian ladjani
*/

#include <unistd.h>
#include "navy.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    i++;
  return (i);
}

int	is_alpha(char c)
{
  if (c >= 'A' && c <= 'H')
    return (1);
  return (0);
}

int	is_num(char c)
{
  if (c >= '1' && c <= '8')
    return (1);
  return (0);
}

int		my_getnbru(char *str)
{
  unsigned int	digit;
  int		counter;

  digit = 0;
  counter = 0;
  while (*str >= '0' && *str <= '9' && *str != '\0')
    {
      digit = digit * 10;
      digit = digit + *str - 48;
      str++;
      counter++;
    }
  return (digit);
}

void		my_putstr(char *str)
{
  int		i;

  while (str[i++] != '\0');
  write(1, str, i);
}
