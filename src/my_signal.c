/*
** my_signal.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Jan 31 16:38:41 2017 julian ladjani
** Last update Sun Feb 12 05:36:53 2017 julian ladjani
*/

#include <unistd.h>
#include "navy.h"

void	handler_usr1(int sig, siginfo_t *si, void *unised)
{
  (void)sig;
  (void)unised;
  if (game.opid == 0)
    {
      game.opid = si->si_pid;
      kill(game.opid, SIGUSR2);
    }
  if (game.mode == 1 && si->si_pid == game.opid)
    game.poshit[0] += 1;
  else if (game.mode == 2 && si->si_pid == game.opid)
    game.poshit[1] += 1;
  else if (game.mode == 0 && si->si_pid == game.opid)
    game.poshit[2] += 1;
}

void	handler_usr2(int sig, siginfo_t *si, void *unised)
{
  (void)sig;
  (void)unised;
  if (game.opid == 0)
    game.opid = si->si_pid;
  else if (game.mode <= 1)
    game.mode++;
  else
    game.mode = 0;
}

void	my_sendpos(int posx, int posy)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  kill(game.opid, SIGUSR2);
  usleep(50);
  while (x < posx)
    {
      kill(game.opid, SIGUSR1);
      x++;
      usleep(50);
    }
  kill(game.opid, SIGUSR2);
  usleep(50);
  while (y < posy)
    {
      kill(game.opid, SIGUSR1);
      y++;
      usleep(50);
    }
  kill(game.opid, SIGUSR2);
}

void	send_hit(int hit)
{
  int	i;

  i = 0;
  while (i < hit)
    {
      kill(game.opid, SIGUSR1);
      i++;
      usleep(50);
    }
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
