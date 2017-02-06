/*
** basic_funcs.c for navy in /home/shielder/Projects/PSU/PSU_2016_navy
** 
** Made by Maxime PICOT
** Login   <shielder@epitech.net>
** 
** Started on  Thu Feb  2 14:00:20 2017 Maxime PICOT
** Last update Fri Feb  3 16:52:21 2017 Maxime PICOT
*/

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
