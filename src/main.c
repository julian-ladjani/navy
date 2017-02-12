/*
** main.c for navy in /home/maxime.picot/Work/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <maxime.picot@epitech.net>
** 
** Started on  Tue Jan 31 15:14:08 2017 Maxime PICOT
** Last update Sun Feb 12 05:40:47 2017 julian ladjani
*/

#include "navy.h"

void		player_waitconnect()
{
  my_printf("waiting for enemy connection...\n\n");
  while (game.opid == 0);
  kill(game.opid, SIGUSR2);
  my_printf("enemy connected\n\n");
}

int		player_connect(char *spid)
{
  pid_t		opid;

  opid = my_getnbru(spid);
  kill(opid, SIGUSR1);
  while (game.opid == 0);
  my_printf("successfully connected");
  return (1);
}



int		main(int ac, char **av)
{
  char		**map;
  char		**omap;

  display_pid();
  if ((omap = my_setmap()) == NULL)
    return (84);
  if (ac == 2 && (map = nav_parser(av[1])) != NULL)
    player_waitconnect();
  else if (ac == 3 && (map = nav_parser(av[2])) != NULL)
    {
      if (player_connect(av[1]) == 0)
	return (84);
    }
  else
    return (84);
}
