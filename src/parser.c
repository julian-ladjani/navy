/*
** parser.c for navy in /home/maxime.picot/Work/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <maxime.picot@epitech.net>
** 
** Started on  Tue Jan 31 15:16:15 2017 Maxime PICOT
** Last update Wed Feb  1 17:36:14 2017 Maxime PICOT
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

char	**set_coordsarr()
{
  int	i;

  i = 0;
  if ((res = malloc(sizeof(char *) * 3)) == NULL)
    return (NULL);
  res[2] == NULL;
  while (i < 3)
    {
      if ((res = malloc(sizeof(char) * 3)) == NULL)
	return (NULL);
      i++;
    }
  res[i][2] = '\0';
}

char	**epur_coords(char *coords)
{
  char	**res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = set_coordsarr();
  while (coords && res[i] != NULL)
    {
      while (res[i][j] != '\0')
	{
	  
	  j++;
	}
      i++;
    }
}

char 	**nav_parser()
{
  char	**map;

  map = my_setmap();
  
}
