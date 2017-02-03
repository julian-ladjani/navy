/*
** my_signal.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Jan 31 16:38:41 2017 julian ladjani
** Last update Fri Feb  3 16:54:33 2017 Maxime PICOT
*/

#include "navy.h"

void	handler_usr1(int sig, siginfo_t *si, void *unised)
{
  if (game.mode == 0)
    kill(game.opid, SIGUSR1);
  if (game.mode == 1)
    game.posx++;
  if (game.mode == 2)
    game.posy++;
}

void	handler_usr2(int sig, siginfo_t *si, void *unised)
{
  if (game.mode <= 1)
    game.mode++;
  else
    game.mode = 0;
}

void	my_sendpos()
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  kill(game.opid, SIGUSR2);
  usleep(50);
  while (x < game.posx)
    {
      kill(game.opid, SIGUSR1);
      x++;
      usleep(50);
    }
  kill(game.opid, SIGUSR2);
  usleep(50);
  while (y < game.posy)
    {
      kill(game.opid, SIGUSR1);
      y++;
      usleep(50);
    }
  kill(game.opid, SIGUSR2);
}

void	my_sendidle()
{
  kill(game.opid, SIGUSR1);
}

void			prepare_my_signal()
{
  struct sigaction      sa;
  struct sigaction	sb;

  sa.sa_flags = SA_SIGINFO;
  sigemptyset(&sa.sa_mask);
  sa.sa_sigaction = handler_usr1;
  sb.sa_flags = SA_SIGINFO;
  sigemptyset(&sb.sa_mask);
  sb.sa_sigaction = handler_usr2;
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sb, NULL);
}
