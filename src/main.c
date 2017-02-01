/*
** main.c for navy in /home/maxime.picot/Work/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <maxime.picot@epitech.net>
** 
** Started on  Tue Jan 31 15:14:08 2017 Maxime PICOT
** Last update Wed Feb  1 15:35:52 2017 Maxime PICOT
*/

int	main(int ac, char **av)
{
  char	*coords;
  int	i;

  i = 0;
  if (ac == 2) // player 1 -> binaire + coords des bateaux
    {
	while (av[1] && coords != NULL && i < 5)
	  {
	    coords = get_next_line(1);
	    i++;
	  }
    }
  else if (ac == 3) // player 2 -> binaire + pid du P1 + coords
    {
      
    }
  else
    return (0);
}
