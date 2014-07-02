/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  sigchldwait.c
 *
 *         Editor:  vim :set et ts=2 sts=2 sw=2
 *
 *         Author:  Martin Y. Yang , yang@libpix.org
 *
 *    Description:  
 *
 * =============================================================
 */

/**
 * @file
 * @brief Figure 5.7 Version of SIGCHLD signal handler that calls wait (improved in Figure 5.11)
 * @see sigchldwaitpid.c
 */
#include "unp.h"

void sig_chld1(int signo)
{
  pid_t pid;
  int stat;

  pid = wait(&stat);
  printf("child %d terminated\n", pid);
  return;
}


