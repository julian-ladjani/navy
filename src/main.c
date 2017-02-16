/*
** main.c for navy in /home/maxime.picot/Work/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <maxime.picot@epitech.net>
** 
** Started on  Tue Jan 31 15:14:08 2017 Maxime PICOT
** Last update Wed Feb 15 23:28:27 2017 julian ladjani
*/

#include "navy.h"

void		player_waitconnect()
{
  my_printf("waiting for enemy connection...\n\n");
  while (g_game.opid == 0);
  kill(g_game.opid, SIGUSR2);
  g_game.poshit[3] = 1;
  my_printf("enemy connected\n\n");
}

int		player_connect(char *spid)
{
  pid_t		opid;

  opid = my_getnbru(spid);
  kill(opid, SIGUSR1);
  while (g_game.opid == 0);
  my_printf("successfully connected\n\n");
  g_game.poshit[3] = 2;
  return (1);
}

int		prepare_my_struct()
{
  g_game.opid = 0;
  g_game.mode = NONE;
  if ((g_game.poshit = malloc(4 * sizeof(int))) == NULL)
    return (0);
  g_game.poshit[0] = 0;
  g_game.poshit[1] = 0;
  g_game.poshit[2] = 0;
  g_game.poshit[3] = 0;
  return (1);
}

int		main(int ac, char **av)
{
  char		**map;
  char		**omap;

  display_pid();
  prepare_my_signal();
  if (prepare_my_struct() == 0)
    return (84);
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
  the_game(map, omap);
}
