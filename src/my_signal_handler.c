/*
** my_signal.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Jan 31 16:38:41 2017 julian ladjani
** Last update Wed Feb 15 06:45:33 2017 julian ladjani
*/

#include <unistd.h>
#include "navy.h"

void	handler_usr1(int sig, siginfo_t *si, void *unised)
{
  (void)sig;
  (void)unised;
  if (g_game.opid == 0)
    {
      g_game.opid = si->si_pid;
      kill(g_game.opid, SIGUSR2);
    }
  else if (g_game.opid == si->si_pid)
    {
      if (g_game.mode >= SENDPOSX && g_game.mode <= SENDHIT)
	sender_action();
      else if (g_game.mode >= RECPOSX && g_game.mode <= RECHIT)
	handler_action();
    }
}

void	handler_action()
{
  if (g_game.mode == RECPOSX)
    g_game.poshit[0] += 1;
  else if (g_game.mode == RECPOSY)
    g_game.poshit[1] += 1;
  else if (g_game.mode == RECHIT)
    g_game.poshit[2] += 1;
  kill(g_game.opid, SIGUSR1);
  pause();
}

void	handler_usr2(int sig, siginfo_t *si, void *unised)
{
  (void)sig;
  (void)unised;
  if (g_game.opid == 0)
    g_game.opid = si->si_pid;
  else if (g_game.mode == RECPOSX && g_game.opid == si->si_pid)
    {
      g_game.mode += 1;
      kill(g_game.opid, SIGUSR1);
      pause();
    }
  else if ((g_game.mode == RECPOSY || g_game.mode == RECHIT)
	   && g_game.opid == si->si_pid)
    g_game.mode = NONE;
}
