/*
** my_signal.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Jan 31 16:38:41 2017 julian ladjani
** Last update Wed Feb 15 20:26:22 2017 julian ladjani
*/

#include <unistd.h>
#include "navy.h"

void	start_sender(int type, int value)
{
  if (type == SENDPOSX)
    {
      g_game.mode = SENDPOSX;
      sender_send(0);
    }
  else if (type == SENDHIT)
    {
      g_game.poshit[2] = value;
      g_game.mode = SENDHIT;
      sender_send(2);
    }
}

void	sender_action()
{
  if (g_game.mode == SENDPOSX)
    {
      if (g_game.poshit[0] > 0)
	sender_send(0);
      else
	sender_changemode();
    }
  else if (g_game.mode == SENDPOSY)
    {
      if (g_game.poshit[1] > 0)
        sender_send(1);
      else
        sender_changemode();
    }
  else if (g_game.mode == SENDHIT)
    {
      if (g_game.poshit[2] > 0)
        sender_send(2);
      else
        sender_changemode();
    }
}

void	sender_send(int type)
{
  g_game.poshit[type] -= 1;
  kill(g_game.opid, SIGUSR1);
  pause();
}

void	sender_changemode()
{
  if (g_game.mode == SENDPOSX)
    {
      g_game.mode = SENDPOSY;
      kill(g_game.opid, SIGUSR2);
      pause();
    }
  else if (g_game.mode == SENDPOSY || g_game.mode == SENDHIT)
    g_game.mode = NONE;
}
