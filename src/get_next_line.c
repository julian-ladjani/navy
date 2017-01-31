/*
** get_next_line.c for get_next_line in /home/julian-ladjani/delivery/GNL/CPE_2016_getnextline
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Mon Jan  2 15:00:28 2017 julian ladjani
** Last update Tue Jan 31 16:24:01 2017 julian ladjani
*/

#include <navy.h>

char		*my_strloc(char *buff)
{
  char		*dest;
  int		i;

  i = 0;
  while (buff && buff[i] != '\0')
    i++;
  if ((dest = malloc((i + READ_SIZE + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (buff && buff[i] != '\0')
    {
      dest[i] = buff[i];
      i++;
    }
  dest[i] = '\0';
  free(buff);
  return (dest);
}

char		*my_line(char *buff, int *nbchar, int last)
{
  int		i;
  int		j;
  char		*temp;

  i = 0;
  j = 0;
  while (buff[i] != '\n' && buff[i] != '\0')
    i++;
  if (buff && (buff[i] != '\0' || (last == 1 && i > 0)))
    {
      if ((temp = malloc((i + 1) * sizeof(char))) == NULL)
	return (NULL);
      while (j < i && buff[j] != '\0')
	{
	  temp[j] = buff[j];
	  j++;
	}
      temp[j] = '\0';
      j++;
      *nbchar += j;
      return (temp);
    }
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static int	offset = 0;
  static int	nbchar = 0;
  static char	*buff = NULL;
  char		*line;
  int		len;

  if (buff == NULL)
    {
      if ((buff = malloc((READ_SIZE + 1) * sizeof(char))) == NULL)
	return (NULL);
      buff[0] = '\0';
    }
  if (buff[0] != '\0' && (line = my_line(buff + nbchar, &nbchar, 0)) != NULL)
    return (line);
  while ((len = read(fd, buff + offset, READ_SIZE)) > 0 && (offset += len) > 0)
    {
      buff[offset] = '\0';
      if ((buff = my_strloc(buff)) == NULL)
	return (NULL);
      if ((line = my_line(buff + nbchar, &nbchar, 0)) != NULL)
	return (line);
    }
  if ((line = my_line(buff + nbchar, &nbchar, 1)) != NULL)
    return (line);
  return (NULL);
}
