/*
** parser.c for navy in /home/maxime.picot/Work/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <maxime.picot@epitech.net>
** 
** Started on  Tue Jan 31 15:16:15 2017 Maxime PICOT
** Last update Fri Feb  3 01:22:42 2017 Maxime PICOT
*/

char	**my_setmap()
{
  char	**map;
  int	i;
  int	j;

  i = 0;
  if ((map = malloc(sizeof(char *) * 9)) == NULL)
    return (NULL);
  while (i < 9)
    {
      if ((map[i] = malloc(sizeof(char) * 9)) == NULL)
	return (NULL);
      while (j < 9)
	{
	  map[i][j] = '.';
	  j++;
	}
      map[i][j] = '\0';
      i++;
      j = 0;
    }
  return (map);
}

char	**set_coordstab()
{
  char	**arr;
  int	i;

  i = 0;
  if ((arr = malloc(sizeof(char *) * 3)) == NULL)
    return (NULL);
  arr[3] == NULL;
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

  fd = open(path, O_RDONLY);
  map = my_setmap();
  map = edit_map(map, fd);
  return (map)
}

t_coords	coords_parser(char *line)
{
  t_coords	coords;
  int		i;
  int		j;
  int		k;
  
  i = 2;
  j = 0;
  k = 0;
  coords = set_coordstab();
  if (line && my_strlen(line) == 7)
    {
      while (i < 6)
	{
	  if (line[0] >= '2' && line[0] <= '5'
	      && line[1] == ':' && line[4] == ':')
	    {
	      while (i < 5)
		{
		  if (is_num(line[i]) == 1)
		    coords.fx = line[i];
		  else if (is_alpha(line[i]) == 1)
		    coords.fy = convertcoords(line[i]);
		  else
		    i++;
		  i++;
		}
	    }
	}
    }
  return (0);
}

char	**edit_map(char **map, int fd)
{
  char	*line;
  int	i;

  i = 0;
  while ((line = my_getnextline(fd)) != NULL)
    {
      if (i > 8)
	return (NULL);
      parse_my_line(line, map);
      i++;
    }
}
