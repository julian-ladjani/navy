/*
** loadfile.c for wolf3d in /home/shielder/Projects/eGraph/wolf3d/src
**
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
**
** Started on  Mon Jan  2 12:22:29 2017 Maxime PICOT
** Last update	Tue Jan 03 13:51:05 2017 Maxime PICOT
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int	my_strlenm(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	i++;
    }
  return (i);
}

char    *my_strcatm(char *dest, char *src)
{
  char  *res;
  int   size;
  int   i;
  int   j;

  size = my_strlenm(dest) + my_strlenm(src);
  if ((res = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  i = -1;
  j = 0;
  if (dest != NULL)
    while (dest[++i] != '\0')
      res[j++] = dest[i];
  i = -1;
  if (src != NULL)
    while (src[++i] != '\0')
      res[j++] = src[i];
  res[j] = '\0';
  free(dest);
  return (res);
}

char	*create_buffer(char *filepath)
{
  char	*buff;
  char	*dest;
  int	file;
  int	rd;

  dest = my_strdup("");
  buff = malloc(sizeof(char) * 513);
  if ((file = open(filepath, O_RDONLY)) < 0)
    return (0);
  buff = my_memset(buff, '\0', 512);
  while ((rd = read(file, buff, 512)) > 0)
    {
      dest = my_strcatm(dest, buff);
      buff = my_memset(buff, '\0', 512);
    }
  if ((my_strlen(dest)) == 0)
    return (NULL);
  free(buff);
  return (dest);
}
