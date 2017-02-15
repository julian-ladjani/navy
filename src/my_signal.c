/*
** my_signal.c for navy in /home/julian-ladjani/delivery/PSU/navy/PSU_2016_navy
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Jan 31 16:38:41 2017 julian ladjani
** Last update Wed Feb 15 04:30:53 2017 julian ladjani
*/

#include <unistd.h>
#include "navy.h"

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
