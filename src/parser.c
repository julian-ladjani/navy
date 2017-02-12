/*
** parser.c for navy in /home/maxime.picot/Work/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <maxime.picot@epitech.net>
** 
** Started on  Tue Jan 31 15:16:15 2017 Maxime PICOT
** Last update Sun Feb 12 05:23:28 2017 julian ladjani
*/

#include "navy.h"

char	**my_setmap()
{
  char	**map;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((map = malloc(sizeof(char *) * 9)) == NULL)
    return (NULL);
  while (i < 8)
    {
      if ((map[i] = malloc(sizeof(char) * 9)) == NULL)
	return (NULL);
      while (j < 8)
	{
	  map[i][j] = '.';
	  j++;
	}
      map[i][j] = '\0';
      i++;
      j = 0;
    }
  map[i] = NULL;
  return (map);
}

char	**set_coordstab()
{
  char	**arr;
  int	i;

  i = 0;
  if ((arr = malloc(sizeof(char *) * 3)) == NULL)
    return (NULL);
  arr[3] = NULL;
  while (i < 3)
    {
      if ((arr[i] = malloc(sizeof(char) * 3)) == NULL)
	return (NULL);
      i++;
    }
  return (arr);
}

char 	**nav_parser(char *path)
{
  char	**map;
  int	fd;

  if ((fd = open(path, O_RDONLY)) < 0)
    return (NULL);
  map = my_setmap();
  map = edit_map(map, fd);
  return (map);
}

t_coords	coords_parser(char *line)
{
  t_coords	coords;
  int		i;

  i = 0;
  if (line && my_strlen(line) == 7)
    {
      while (i < 6)
	{
	  if (line[0] >= '2' && line[0] <= '5'
	      && line[1] == ':' && line[4] == ':')
	    {
	      if (is_num(line[i]) == 1 && ((i == 1) || (i == 2)))
		coords.fx = my_convertcoords(line[i], 1);
	      else if (is_alpha(line[i]) == 1 && ((i == 1) || (i == 2)))
		coords.fy = my_convertcoords(line[i], 2);
	      else if (is_num(line[i]) == 1 && ((i == 4) || (i == 5)))
		coords.lx = my_convertcoords(line[i], 1);
	      else if (is_alpha(line[i]) == 1 && ((i == 4) || (i == 5)))
		coords.ly = my_convertcoords(line[i], 2);
	      i++;
	    }
	}
    }
  return (coords);
}

char		**edit_map(char **map, int fd)
{
  char		*line;
  int		i;

  i = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      if (i > 8)
	return (NULL);
      //coords_parser(line);
      i++;
    }
  if (i < 8)
    return (NULL);
  return (map);
}
