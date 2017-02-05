/*
** main.c for navy in /home/maxime.picot/Work/PSU/PSU_2016_navy/src
** 
** Made by Maxime PICOT
** Login   <maxime.picot@epitech.net>
** 
** Started on  Tue Jan 31 15:14:08 2017 Maxime PICOT
** Last update Mon Feb  6 00:27:15 2017 Maxime PICOT
*/

#include "navy.h"

int		main(int ac, char **av)
{
  t_game	game;
  t_coords	coords;

  (void)game;
  (void)coords;
  display_pid();
  if (ac == 2) // player 1 -> binaire + coords des bateaux
    {
      game.map = nav_parser(av[1]);
      my_printf("waiting for ennemy connexion...");
    }
  else if (ac == 3) // player 2 -> binaire + pid du P1 + coords
    {
      game.map = nav_parser(av[2]);
    }
  else
    return (0);
  if (game.map == NULL)
    return (84);
}
